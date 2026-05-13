#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void playVoice_0x150(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010447C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80104480: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80104484: jal         0x800C7CF8
    // 0x80104488: addiu       $a0, $zero, 0x150
    ctx->r4 = ADD32(0, 0X150);
    playObjectiveVoiceLine1(rdram, ctx);
        goto after_0;
    // 0x80104488: addiu       $a0, $zero, 0x150
    ctx->r4 = ADD32(0, 0X150);
    after_0:
    // 0x8010448C: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80104490: jr          $ra
    // 0x80104494: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80104494: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void playVoice_0x296(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80104498: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8010449C: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x801044A0: jal         0x800C7CF8
    // 0x801044A4: addiu       $a0, $zero, 0x296
    ctx->r4 = ADD32(0, 0X296);
    playObjectiveVoiceLine1(rdram, ctx);
        goto after_0;
    // 0x801044A4: addiu       $a0, $zero, 0x296
    ctx->r4 = ADD32(0, 0X296);
    after_0:
    // 0x801044A8: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x801044AC: jr          $ra
    // 0x801044B0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x801044B0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void lv6_dispatchStageTick(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801044B4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801044B8: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x801044BC: addiu       $a0, $a0, -0x68A0
    ctx->r4 = ADD32(ctx->r4, -0X68A0);
    // 0x801044C0: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x801044C4: jal         0x800C7D60
    // 0x801044C8: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    delegateToLevelStageTick(rdram, ctx);
        goto after_0;
    // 0x801044C8: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_0:
    // 0x801044CC: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x801044D0: jr          $ra
    // 0x801044D4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x801044D4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void fake_func_801044D8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
;}
RECOMP_FUNC void lv7_checkComplexObjectives(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801044E0: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x801044E4: sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // 0x801044E8: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x801044EC: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x801044F0: sdc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X28, ctx->r29);
    // 0x801044F4: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x801044F8: jal         0x800C759C
    // 0x801044FC: addiu       $a0, $zero, 0x61
    ctx->r4 = ADD32(0, 0X61);
    getObjectiveBoolean(rdram, ctx);
        goto after_0;
    // 0x801044FC: addiu       $a0, $zero, 0x61
    ctx->r4 = ADD32(0, 0X61);
    after_0:
    // 0x80104500: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // 0x80104504: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80104508: bne         $s0, $v0, L_80104574
    if (ctx->r16 != ctx->r2) {
        // 0x8010450C: nop
    
            goto L_80104574;
    }
    // 0x8010450C: nop

    // 0x80104510: jal         0x800C759C
    // 0x80104514: addiu       $a0, $zero, 0x62
    ctx->r4 = ADD32(0, 0X62);
    getObjectiveBoolean(rdram, ctx);
        goto after_1;
    // 0x80104514: addiu       $a0, $zero, 0x62
    ctx->r4 = ADD32(0, 0X62);
    after_1:
    // 0x80104518: bne         $v0, $zero, L_80104574
    if (ctx->r2 != 0) {
        // 0x8010451C: nop
    
            goto L_80104574;
    }
    // 0x8010451C: nop

    // 0x80104520: jal         0x800C759C
    // 0x80104524: addiu       $a0, $zero, 0x63
    ctx->r4 = ADD32(0, 0X63);
    getObjectiveBoolean(rdram, ctx);
        goto after_2;
    // 0x80104524: addiu       $a0, $zero, 0x63
    ctx->r4 = ADD32(0, 0X63);
    after_2:
    // 0x80104528: bne         $v0, $zero, L_80104574
    if (ctx->r2 != 0) {
        // 0x8010452C: lui         $v1, 0x8011
        ctx->r3 = S32(0X8011 << 16);
            goto L_80104574;
    }
    // 0x8010452C: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x80104530: lw          $v0, -0x2F68($v1)
    ctx->r2 = MEM_W(ctx->r3, -0X2F68);
    // 0x80104534: bne         $v0, $zero, L_80104574
    if (ctx->r2 != 0) {
        // 0x80104538: lui         $a0, 0x800B
        ctx->r4 = S32(0X800B << 16);
            goto L_80104574;
    }
    // 0x80104538: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x8010453C: addiu       $a0, $a0, -0x6880
    ctx->r4 = ADD32(ctx->r4, -0X6880);
    // 0x80104540: jal         0x800C7884
    // 0x80104544: sw          $s0, -0x2F68($v1)
    MEM_W(-0X2F68, ctx->r3) = ctx->r16;
    setHudFlagBit40AndStoreArg(rdram, ctx);
        goto after_3;
    // 0x80104544: sw          $s0, -0x2F68($v1)
    MEM_W(-0X2F68, ctx->r3) = ctx->r16;
    after_3:
    // 0x80104548: addiu       $a0, $zero, 0x3D
    ctx->r4 = ADD32(0, 0X3D);
    // 0x8010454C: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80104550: lwc1        $f20, -0x6848($at)
    ctx->f20.u32l = MEM_W(ctx->r1, -0X6848);
    // 0x80104554: jal         0x800C7540
    // 0x80104558: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    setObjectiveBoolean(rdram, ctx);
        goto after_4;
    // 0x80104558: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_4:
    // 0x8010455C: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80104560: jal         0x800C7D1C
    // 0x80104564: addiu       $a0, $zero, 0x8A
    ctx->r4 = ADD32(0, 0X8A);
    playObjectiveVoiceLine2(rdram, ctx);
        goto after_5;
    // 0x80104564: addiu       $a0, $zero, 0x8A
    ctx->r4 = ADD32(0, 0X8A);
    after_5:
    // 0x80104568: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x8010456C: jal         0x800C7D1C
    // 0x80104570: addiu       $a0, $zero, 0x11A
    ctx->r4 = ADD32(0, 0X11A);
    playObjectiveVoiceLine2(rdram, ctx);
        goto after_6;
    // 0x80104570: addiu       $a0, $zero, 0x11A
    ctx->r4 = ADD32(0, 0X11A);
    after_6:
L_80104574:
    // 0x80104574: jal         0x800C759C
    // 0x80104578: addiu       $a0, $zero, 0x61
    ctx->r4 = ADD32(0, 0X61);
    getObjectiveBoolean(rdram, ctx);
        goto after_7;
    // 0x80104578: addiu       $a0, $zero, 0x61
    ctx->r4 = ADD32(0, 0X61);
    after_7:
    // 0x8010457C: bne         $v0, $zero, L_801045E8
    if (ctx->r2 != 0) {
        // 0x80104580: nop
    
            goto L_801045E8;
    }
    // 0x80104580: nop

    // 0x80104584: jal         0x800C759C
    // 0x80104588: addiu       $a0, $zero, 0x62
    ctx->r4 = ADD32(0, 0X62);
    getObjectiveBoolean(rdram, ctx);
        goto after_8;
    // 0x80104588: addiu       $a0, $zero, 0x62
    ctx->r4 = ADD32(0, 0X62);
    after_8:
    // 0x8010458C: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // 0x80104590: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80104594: bne         $s0, $v0, L_801045E8
    if (ctx->r16 != ctx->r2) {
        // 0x80104598: nop
    
            goto L_801045E8;
    }
    // 0x80104598: nop

    // 0x8010459C: jal         0x800C759C
    // 0x801045A0: addiu       $a0, $zero, 0x63
    ctx->r4 = ADD32(0, 0X63);
    getObjectiveBoolean(rdram, ctx);
        goto after_9;
    // 0x801045A0: addiu       $a0, $zero, 0x63
    ctx->r4 = ADD32(0, 0X63);
    after_9:
    // 0x801045A4: bne         $v0, $zero, L_801045E8
    if (ctx->r2 != 0) {
        // 0x801045A8: lui         $v1, 0x8011
        ctx->r3 = S32(0X8011 << 16);
            goto L_801045E8;
    }
    // 0x801045A8: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x801045AC: lw          $v0, -0x2F70($v1)
    ctx->r2 = MEM_W(ctx->r3, -0X2F70);
    // 0x801045B0: bne         $v0, $zero, L_801045E8
    if (ctx->r2 != 0) {
        // 0x801045B4: lui         $a0, 0x800B
        ctx->r4 = S32(0X800B << 16);
            goto L_801045E8;
    }
    // 0x801045B4: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x801045B8: addiu       $a0, $a0, -0x6878
    ctx->r4 = ADD32(ctx->r4, -0X6878);
    // 0x801045BC: jal         0x800C7884
    // 0x801045C0: sw          $s0, -0x2F70($v1)
    MEM_W(-0X2F70, ctx->r3) = ctx->r16;
    setHudFlagBit40AndStoreArg(rdram, ctx);
        goto after_10;
    // 0x801045C0: sw          $s0, -0x2F70($v1)
    MEM_W(-0X2F70, ctx->r3) = ctx->r16;
    after_10:
    // 0x801045C4: addiu       $a0, $zero, 0x40
    ctx->r4 = ADD32(0, 0X40);
    // 0x801045C8: jal         0x800C7540
    // 0x801045CC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    setObjectiveBoolean(rdram, ctx);
        goto after_11;
    // 0x801045CC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_11:
    // 0x801045D0: lui         $a1, 0x3F00
    ctx->r5 = S32(0X3F00 << 16);
    // 0x801045D4: jal         0x800C7D1C
    // 0x801045D8: addiu       $a0, $zero, 0x2A6
    ctx->r4 = ADD32(0, 0X2A6);
    playObjectiveVoiceLine2(rdram, ctx);
        goto after_12;
    // 0x801045D8: addiu       $a0, $zero, 0x2A6
    ctx->r4 = ADD32(0, 0X2A6);
    after_12:
    // 0x801045DC: lui         $a1, 0x4040
    ctx->r5 = S32(0X4040 << 16);
    // 0x801045E0: jal         0x800C7D1C
    // 0x801045E4: addiu       $a0, $zero, 0x8B
    ctx->r4 = ADD32(0, 0X8B);
    playObjectiveVoiceLine2(rdram, ctx);
        goto after_13;
    // 0x801045E4: addiu       $a0, $zero, 0x8B
    ctx->r4 = ADD32(0, 0X8B);
    after_13:
L_801045E8:
    // 0x801045E8: jal         0x800C759C
    // 0x801045EC: addiu       $a0, $zero, 0x61
    ctx->r4 = ADD32(0, 0X61);
    getObjectiveBoolean(rdram, ctx);
        goto after_14;
    // 0x801045EC: addiu       $a0, $zero, 0x61
    ctx->r4 = ADD32(0, 0X61);
    after_14:
    // 0x801045F0: bne         $v0, $zero, L_8010465C
    if (ctx->r2 != 0) {
        // 0x801045F4: nop
    
            goto L_8010465C;
    }
    // 0x801045F4: nop

    // 0x801045F8: jal         0x800C759C
    // 0x801045FC: addiu       $a0, $zero, 0x62
    ctx->r4 = ADD32(0, 0X62);
    getObjectiveBoolean(rdram, ctx);
        goto after_15;
    // 0x801045FC: addiu       $a0, $zero, 0x62
    ctx->r4 = ADD32(0, 0X62);
    after_15:
    // 0x80104600: bne         $v0, $zero, L_8010465C
    if (ctx->r2 != 0) {
        // 0x80104604: nop
    
            goto L_8010465C;
    }
    // 0x80104604: nop

    // 0x80104608: jal         0x800C759C
    // 0x8010460C: addiu       $a0, $zero, 0x63
    ctx->r4 = ADD32(0, 0X63);
    getObjectiveBoolean(rdram, ctx);
        goto after_16;
    // 0x8010460C: addiu       $a0, $zero, 0x63
    ctx->r4 = ADD32(0, 0X63);
    after_16:
    // 0x80104610: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x80104614: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80104618: bne         $v1, $v0, L_8010465C
    if (ctx->r3 != ctx->r2) {
        // 0x8010461C: lui         $a1, 0x8011
        ctx->r5 = S32(0X8011 << 16);
            goto L_8010465C;
    }
    // 0x8010461C: lui         $a1, 0x8011
    ctx->r5 = S32(0X8011 << 16);
    // 0x80104620: lw          $v0, -0x2F6C($a1)
    ctx->r2 = MEM_W(ctx->r5, -0X2F6C);
    // 0x80104624: bne         $v0, $zero, L_8010465C
    if (ctx->r2 != 0) {
        // 0x80104628: lui         $a0, 0x800B
        ctx->r4 = S32(0X800B << 16);
            goto L_8010465C;
    }
    // 0x80104628: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x8010462C: addiu       $a0, $a0, -0x6870
    ctx->r4 = ADD32(ctx->r4, -0X6870);
    // 0x80104630: jal         0x800C7884
    // 0x80104634: sw          $v1, -0x2F6C($a1)
    MEM_W(-0X2F6C, ctx->r5) = ctx->r3;
    setHudFlagBit40AndStoreArg(rdram, ctx);
        goto after_17;
    // 0x80104634: sw          $v1, -0x2F6C($a1)
    MEM_W(-0X2F6C, ctx->r5) = ctx->r3;
    after_17:
    // 0x80104638: addiu       $a0, $zero, 0x43
    ctx->r4 = ADD32(0, 0X43);
    // 0x8010463C: jal         0x800C7540
    // 0x80104640: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    setObjectiveBoolean(rdram, ctx);
        goto after_18;
    // 0x80104640: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_18:
    // 0x80104644: lui         $a1, 0x3F00
    ctx->r5 = S32(0X3F00 << 16);
    // 0x80104648: jal         0x800C7D1C
    // 0x8010464C: addiu       $a0, $zero, 0x2A6
    ctx->r4 = ADD32(0, 0X2A6);
    playObjectiveVoiceLine2(rdram, ctx);
        goto after_19;
    // 0x8010464C: addiu       $a0, $zero, 0x2A6
    ctx->r4 = ADD32(0, 0X2A6);
    after_19:
    // 0x80104650: lui         $a1, 0x4040
    ctx->r5 = S32(0X4040 << 16);
    // 0x80104654: jal         0x800C7D1C
    // 0x80104658: addiu       $a0, $zero, 0x8A
    ctx->r4 = ADD32(0, 0X8A);
    playObjectiveVoiceLine2(rdram, ctx);
        goto after_20;
    // 0x80104658: addiu       $a0, $zero, 0x8A
    ctx->r4 = ADD32(0, 0X8A);
    after_20:
L_8010465C:
    // 0x8010465C: jal         0x800C761C
    // 0x80104660: addiu       $a0, $zero, 0x14
    ctx->r4 = ADD32(0, 0X14);
    getObjectiveCount(rdram, ctx);
        goto after_21;
    // 0x80104660: addiu       $a0, $zero, 0x14
    ctx->r4 = ADD32(0, 0X14);
    after_21:
    // 0x80104664: slti        $v0, $v0, 0x15
    ctx->r2 = SIGNED(ctx->r2) < 0X15 ? 1 : 0;
    // 0x80104668: bne         $v0, $zero, L_801046A8
    if (ctx->r2 != 0) {
        // 0x8010466C: nop
    
            goto L_801046A8;
    }
    // 0x8010466C: nop

    // 0x80104670: jal         0x800C759C
    // 0x80104674: addiu       $a0, $zero, 0x61
    ctx->r4 = ADD32(0, 0X61);
    getObjectiveBoolean(rdram, ctx);
        goto after_22;
    // 0x80104674: addiu       $a0, $zero, 0x61
    ctx->r4 = ADD32(0, 0X61);
    after_22:
    // 0x80104678: bne         $v0, $zero, L_801046A8
    if (ctx->r2 != 0) {
        // 0x8010467C: addiu       $a0, $zero, 0x61
        ctx->r4 = ADD32(0, 0X61);
            goto L_801046A8;
    }
    // 0x8010467C: addiu       $a0, $zero, 0x61
    ctx->r4 = ADD32(0, 0X61);
    // 0x80104680: jal         0x800C7540
    // 0x80104684: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    setObjectiveBoolean(rdram, ctx);
        goto after_23;
    // 0x80104684: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_23:
    // 0x80104688: addiu       $a0, $zero, 0x63
    ctx->r4 = ADD32(0, 0X63);
    // 0x8010468C: jal         0x800C75EC
    // 0x80104690: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    increaseObjectiveCount(rdram, ctx);
        goto after_24;
    // 0x80104690: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_24:
    // 0x80104694: jal         0x800C76B0
    // 0x80104698: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    activateObjectiveCompleteFlag(rdram, ctx);
        goto after_25;
    // 0x80104698: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_25:
    // 0x8010469C: addiu       $a0, $zero, 0x78
    ctx->r4 = ADD32(0, 0X78);
    // 0x801046A0: jal         0x800C7540
    // 0x801046A4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    setObjectiveBoolean(rdram, ctx);
        goto after_26;
    // 0x801046A4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_26:
L_801046A8:
    // 0x801046A8: jal         0x800C761C
    // 0x801046AC: addiu       $a0, $zero, 0x1E
    ctx->r4 = ADD32(0, 0X1E);
    getObjectiveCount(rdram, ctx);
        goto after_27;
    // 0x801046AC: addiu       $a0, $zero, 0x1E
    ctx->r4 = ADD32(0, 0X1E);
    after_27:
    // 0x801046B0: slti        $v0, $v0, 0xA
    ctx->r2 = SIGNED(ctx->r2) < 0XA ? 1 : 0;
    // 0x801046B4: bne         $v0, $zero, L_801046F4
    if (ctx->r2 != 0) {
        // 0x801046B8: nop
    
            goto L_801046F4;
    }
    // 0x801046B8: nop

    // 0x801046BC: jal         0x800C759C
    // 0x801046C0: addiu       $a0, $zero, 0x62
    ctx->r4 = ADD32(0, 0X62);
    getObjectiveBoolean(rdram, ctx);
        goto after_28;
    // 0x801046C0: addiu       $a0, $zero, 0x62
    ctx->r4 = ADD32(0, 0X62);
    after_28:
    // 0x801046C4: bne         $v0, $zero, L_801046F4
    if (ctx->r2 != 0) {
        // 0x801046C8: addiu       $a0, $zero, 0x62
        ctx->r4 = ADD32(0, 0X62);
            goto L_801046F4;
    }
    // 0x801046C8: addiu       $a0, $zero, 0x62
    ctx->r4 = ADD32(0, 0X62);
    // 0x801046CC: jal         0x800C7540
    // 0x801046D0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    setObjectiveBoolean(rdram, ctx);
        goto after_29;
    // 0x801046D0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_29:
    // 0x801046D4: addiu       $a0, $zero, 0x63
    ctx->r4 = ADD32(0, 0X63);
    // 0x801046D8: jal         0x800C75EC
    // 0x801046DC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    increaseObjectiveCount(rdram, ctx);
        goto after_30;
    // 0x801046DC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_30:
    // 0x801046E0: jal         0x800C76B0
    // 0x801046E4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    activateObjectiveCompleteFlag(rdram, ctx);
        goto after_31;
    // 0x801046E4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_31:
    // 0x801046E8: addiu       $a0, $zero, 0x79
    ctx->r4 = ADD32(0, 0X79);
    // 0x801046EC: jal         0x800C7540
    // 0x801046F0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    setObjectiveBoolean(rdram, ctx);
        goto after_32;
    // 0x801046F0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_32:
L_801046F4:
    // 0x801046F4: jal         0x800C761C
    // 0x801046F8: addiu       $a0, $zero, 0x28
    ctx->r4 = ADD32(0, 0X28);
    getObjectiveCount(rdram, ctx);
        goto after_33;
    // 0x801046F8: addiu       $a0, $zero, 0x28
    ctx->r4 = ADD32(0, 0X28);
    after_33:
    // 0x801046FC: slti        $v0, $v0, 0x6
    ctx->r2 = SIGNED(ctx->r2) < 0X6 ? 1 : 0;
    // 0x80104700: bne         $v0, $zero, L_80104740
    if (ctx->r2 != 0) {
        // 0x80104704: nop
    
            goto L_80104740;
    }
    // 0x80104704: nop

    // 0x80104708: jal         0x800C759C
    // 0x8010470C: addiu       $a0, $zero, 0x63
    ctx->r4 = ADD32(0, 0X63);
    getObjectiveBoolean(rdram, ctx);
        goto after_34;
    // 0x8010470C: addiu       $a0, $zero, 0x63
    ctx->r4 = ADD32(0, 0X63);
    after_34:
    // 0x80104710: bne         $v0, $zero, L_80104740
    if (ctx->r2 != 0) {
        // 0x80104714: addiu       $a0, $zero, 0x63
        ctx->r4 = ADD32(0, 0X63);
            goto L_80104740;
    }
    // 0x80104714: addiu       $a0, $zero, 0x63
    ctx->r4 = ADD32(0, 0X63);
    // 0x80104718: jal         0x800C7540
    // 0x8010471C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    setObjectiveBoolean(rdram, ctx);
        goto after_35;
    // 0x8010471C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_35:
    // 0x80104720: addiu       $a0, $zero, 0x63
    ctx->r4 = ADD32(0, 0X63);
    // 0x80104724: jal         0x800C75EC
    // 0x80104728: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    increaseObjectiveCount(rdram, ctx);
        goto after_36;
    // 0x80104728: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_36:
    // 0x8010472C: jal         0x800C76B0
    // 0x80104730: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    activateObjectiveCompleteFlag(rdram, ctx);
        goto after_37;
    // 0x80104730: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_37:
    // 0x80104734: addiu       $a0, $zero, 0x7A
    ctx->r4 = ADD32(0, 0X7A);
    // 0x80104738: jal         0x800C7540
    // 0x8010473C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    setObjectiveBoolean(rdram, ctx);
        goto after_38;
    // 0x8010473C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_38:
L_80104740:
    // 0x80104740: jal         0x800C761C
    // 0x80104744: addiu       $a0, $zero, 0x28
    ctx->r4 = ADD32(0, 0X28);
    getObjectiveCount(rdram, ctx);
        goto after_39;
    // 0x80104744: addiu       $a0, $zero, 0x28
    ctx->r4 = ADD32(0, 0X28);
    after_39:
    // 0x80104748: slti        $v0, $v0, 0x6
    ctx->r2 = SIGNED(ctx->r2) < 0X6 ? 1 : 0;
    // 0x8010474C: bne         $v0, $zero, L_801047A8
    if (ctx->r2 != 0) {
        // 0x80104750: nop
    
            goto L_801047A8;
    }
    // 0x80104750: nop

    // 0x80104754: jal         0x800C761C
    // 0x80104758: addiu       $a0, $zero, 0x1E
    ctx->r4 = ADD32(0, 0X1E);
    getObjectiveCount(rdram, ctx);
        goto after_40;
    // 0x80104758: addiu       $a0, $zero, 0x1E
    ctx->r4 = ADD32(0, 0X1E);
    after_40:
    // 0x8010475C: slti        $v0, $v0, 0xA
    ctx->r2 = SIGNED(ctx->r2) < 0XA ? 1 : 0;
    // 0x80104760: bne         $v0, $zero, L_801047A8
    if (ctx->r2 != 0) {
        // 0x80104764: nop
    
            goto L_801047A8;
    }
    // 0x80104764: nop

    // 0x80104768: jal         0x800C759C
    // 0x8010476C: addiu       $a0, $zero, 0x6A
    ctx->r4 = ADD32(0, 0X6A);
    getObjectiveBoolean(rdram, ctx);
        goto after_41;
    // 0x8010476C: addiu       $a0, $zero, 0x6A
    ctx->r4 = ADD32(0, 0X6A);
    after_41:
    // 0x80104770: bne         $v0, $zero, L_801047A8
    if (ctx->r2 != 0) {
        // 0x80104774: lui         $v1, 0x8011
        ctx->r3 = S32(0X8011 << 16);
            goto L_801047A8;
    }
    // 0x80104774: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x80104778: lw          $v0, -0x2F64($v1)
    ctx->r2 = MEM_W(ctx->r3, -0X2F64);
    // 0x8010477C: bne         $v0, $zero, L_801047A8
    if (ctx->r2 != 0) {
        // 0x80104780: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_801047A8;
    }
    // 0x80104780: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80104784: sw          $v0, -0x2F64($v1)
    MEM_W(-0X2F64, ctx->r3) = ctx->r2;
    // 0x80104788: addiu       $a0, $zero, 0x29
    ctx->r4 = ADD32(0, 0X29);
    // 0x8010478C: jal         0x800C7540
    // 0x80104790: addu        $a1, $v0, $zero
    ctx->r5 = ADD32(ctx->r2, 0);
    setObjectiveBoolean(rdram, ctx);
        goto after_42;
    // 0x80104790: addu        $a1, $v0, $zero
    ctx->r5 = ADD32(ctx->r2, 0);
    after_42:
    // 0x80104794: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x80104798: jal         0x800C7884
    // 0x8010479C: addiu       $a0, $a0, -0x6868
    ctx->r4 = ADD32(ctx->r4, -0X6868);
    setHudFlagBit40AndStoreArg(rdram, ctx);
        goto after_43;
    // 0x8010479C: addiu       $a0, $a0, -0x6868
    ctx->r4 = ADD32(ctx->r4, -0X6868);
    after_43:
    // 0x801047A0: jal         0x800C7D98
    // 0x801047A4: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    triggerSoundCueByType(rdram, ctx);
        goto after_44;
    // 0x801047A4: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_44:
L_801047A8:
    // 0x801047A8: jal         0x800C761C
    // 0x801047AC: addiu       $a0, $zero, 0x14
    ctx->r4 = ADD32(0, 0X14);
    getObjectiveCount(rdram, ctx);
        goto after_45;
    // 0x801047AC: addiu       $a0, $zero, 0x14
    ctx->r4 = ADD32(0, 0X14);
    after_45:
    // 0x801047B0: addiu       $v1, $zero, 0x13
    ctx->r3 = ADD32(0, 0X13);
    // 0x801047B4: bne         $v0, $v1, L_80104860
    if (ctx->r2 != ctx->r3) {
        // 0x801047B8: nop
    
            goto L_80104860;
    }
    // 0x801047B8: nop

    // 0x801047BC: jal         0x800C759C
    // 0x801047C0: addiu       $a0, $zero, 0x62
    ctx->r4 = ADD32(0, 0X62);
    getObjectiveBoolean(rdram, ctx);
        goto after_46;
    // 0x801047C0: addiu       $a0, $zero, 0x62
    ctx->r4 = ADD32(0, 0X62);
    after_46:
    // 0x801047C4: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // 0x801047C8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x801047CC: bne         $s0, $v0, L_80104860
    if (ctx->r16 != ctx->r2) {
        // 0x801047D0: nop
    
            goto L_80104860;
    }
    // 0x801047D0: nop

    // 0x801047D4: jal         0x800C759C
    // 0x801047D8: addiu       $a0, $zero, 0x63
    ctx->r4 = ADD32(0, 0X63);
    getObjectiveBoolean(rdram, ctx);
        goto after_47;
    // 0x801047D8: addiu       $a0, $zero, 0x63
    ctx->r4 = ADD32(0, 0X63);
    after_47:
    // 0x801047DC: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x801047E0: bne         $v1, $s0, L_80104860
    if (ctx->r3 != ctx->r16) {
        // 0x801047E4: lui         $a2, 0x8011
        ctx->r6 = S32(0X8011 << 16);
            goto L_80104860;
    }
    // 0x801047E4: lui         $a2, 0x8011
    ctx->r6 = S32(0X8011 << 16);
    // 0x801047E8: lw          $v0, -0x2F60($a2)
    ctx->r2 = MEM_W(ctx->r6, -0X2F60);
    // 0x801047EC: bne         $v0, $zero, L_80104860
    if (ctx->r2 != 0) {
        // 0x801047F0: addiu       $a0, $zero, 0x32
        ctx->r4 = ADD32(0, 0X32);
            goto L_80104860;
    }
    // 0x801047F0: addiu       $a0, $zero, 0x32
    ctx->r4 = ADD32(0, 0X32);
    // 0x801047F4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x801047F8: jal         0x800C7540
    // 0x801047FC: sw          $v1, -0x2F60($a2)
    MEM_W(-0X2F60, ctx->r6) = ctx->r3;
    setObjectiveBoolean(rdram, ctx);
        goto after_48;
    // 0x801047FC: sw          $v1, -0x2F60($a2)
    MEM_W(-0X2F60, ctx->r6) = ctx->r3;
    after_48:
    // 0x80104800: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x80104804: jal         0x800C7884
    // 0x80104808: addiu       $a0, $a0, -0x6854
    ctx->r4 = ADD32(ctx->r4, -0X6854);
    setHudFlagBit40AndStoreArg(rdram, ctx);
        goto after_49;
    // 0x80104808: addiu       $a0, $a0, -0x6854
    ctx->r4 = ADD32(ctx->r4, -0X6854);
    after_49:
    // 0x8010480C: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x80104810: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80104814: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80104818: lwc1        $f22, -0x6844($at)
    ctx->f22.u32l = MEM_W(ctx->r1, -0X6844);
    // 0x8010481C: jal         0x800C7D1C
    // 0x80104820: addiu       $a0, $zero, 0x23D
    ctx->r4 = ADD32(0, 0X23D);
    playObjectiveVoiceLine2(rdram, ctx);
        goto after_50;
    // 0x80104820: addiu       $a0, $zero, 0x23D
    ctx->r4 = ADD32(0, 0X23D);
    after_50:
    // 0x80104824: mfc1        $a1, $f22
    ctx->r5 = (int32_t)ctx->f22.u32l;
    // 0x80104828: jal         0x800C7D1C
    // 0x8010482C: addiu       $a0, $zero, 0x155
    ctx->r4 = ADD32(0, 0X155);
    playObjectiveVoiceLine2(rdram, ctx);
        goto after_51;
    // 0x8010482C: addiu       $a0, $zero, 0x155
    ctx->r4 = ADD32(0, 0X155);
    after_51:
    // 0x80104830: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80104834: jal         0x800C7D1C
    // 0x80104838: addiu       $a0, $zero, 0x89
    ctx->r4 = ADD32(0, 0X89);
    playObjectiveVoiceLine2(rdram, ctx);
        goto after_52;
    // 0x80104838: addiu       $a0, $zero, 0x89
    ctx->r4 = ADD32(0, 0X89);
    after_52:
    // 0x8010483C: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80104840: jal         0x800C7D1C
    // 0x80104844: addiu       $a0, $zero, 0x103
    ctx->r4 = ADD32(0, 0X103);
    playObjectiveVoiceLine2(rdram, ctx);
        goto after_53;
    // 0x80104844: addiu       $a0, $zero, 0x103
    ctx->r4 = ADD32(0, 0X103);
    after_53:
    // 0x80104848: mfc1        $a1, $f22
    ctx->r5 = (int32_t)ctx->f22.u32l;
    // 0x8010484C: jal         0x800C7D1C
    // 0x80104850: addiu       $a0, $zero, 0x156
    ctx->r4 = ADD32(0, 0X156);
    playObjectiveVoiceLine2(rdram, ctx);
        goto after_54;
    // 0x80104850: addiu       $a0, $zero, 0x156
    ctx->r4 = ADD32(0, 0X156);
    after_54:
    // 0x80104854: mfc1        $a1, $f22
    ctx->r5 = (int32_t)ctx->f22.u32l;
    // 0x80104858: jal         0x800C7D1C
    // 0x8010485C: addiu       $a0, $zero, 0x149
    ctx->r4 = ADD32(0, 0X149);
    playObjectiveVoiceLine2(rdram, ctx);
        goto after_55;
    // 0x8010485C: addiu       $a0, $zero, 0x149
    ctx->r4 = ADD32(0, 0X149);
    after_55:
L_80104860:
    // 0x80104860: jal         0x800C759C
    // 0x80104864: addiu       $a0, $zero, 0x61
    ctx->r4 = ADD32(0, 0X61);
    getObjectiveBoolean(rdram, ctx);
        goto after_56;
    // 0x80104864: addiu       $a0, $zero, 0x61
    ctx->r4 = ADD32(0, 0X61);
    after_56:
    // 0x80104868: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // 0x8010486C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80104870: bne         $s0, $v0, L_80104918
    if (ctx->r16 != ctx->r2) {
        // 0x80104874: nop
    
            goto L_80104918;
    }
    // 0x80104874: nop

    // 0x80104878: jal         0x800C761C
    // 0x8010487C: addiu       $a0, $zero, 0x1E
    ctx->r4 = ADD32(0, 0X1E);
    getObjectiveCount(rdram, ctx);
        goto after_57;
    // 0x8010487C: addiu       $a0, $zero, 0x1E
    ctx->r4 = ADD32(0, 0X1E);
    after_57:
    // 0x80104880: addiu       $v1, $zero, 0x8
    ctx->r3 = ADD32(0, 0X8);
    // 0x80104884: bne         $v0, $v1, L_80104918
    if (ctx->r2 != ctx->r3) {
        // 0x80104888: nop
    
            goto L_80104918;
    }
    // 0x80104888: nop

    // 0x8010488C: jal         0x800C759C
    // 0x80104890: addiu       $a0, $zero, 0x63
    ctx->r4 = ADD32(0, 0X63);
    getObjectiveBoolean(rdram, ctx);
        goto after_58;
    // 0x80104890: addiu       $a0, $zero, 0x63
    ctx->r4 = ADD32(0, 0X63);
    after_58:
    // 0x80104894: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x80104898: bne         $v1, $s0, L_80104918
    if (ctx->r3 != ctx->r16) {
        // 0x8010489C: lui         $a2, 0x8011
        ctx->r6 = S32(0X8011 << 16);
            goto L_80104918;
    }
    // 0x8010489C: lui         $a2, 0x8011
    ctx->r6 = S32(0X8011 << 16);
    // 0x801048A0: lw          $v0, -0x2F60($a2)
    ctx->r2 = MEM_W(ctx->r6, -0X2F60);
    // 0x801048A4: bne         $v0, $zero, L_80104918
    if (ctx->r2 != 0) {
        // 0x801048A8: addiu       $a0, $zero, 0x32
        ctx->r4 = ADD32(0, 0X32);
            goto L_80104918;
    }
    // 0x801048A8: addiu       $a0, $zero, 0x32
    ctx->r4 = ADD32(0, 0X32);
    // 0x801048AC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x801048B0: jal         0x800C7540
    // 0x801048B4: sw          $v1, -0x2F60($a2)
    MEM_W(-0X2F60, ctx->r6) = ctx->r3;
    setObjectiveBoolean(rdram, ctx);
        goto after_59;
    // 0x801048B4: sw          $v1, -0x2F60($a2)
    MEM_W(-0X2F60, ctx->r6) = ctx->r3;
    after_59:
    // 0x801048B8: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x801048BC: jal         0x800C7884
    // 0x801048C0: addiu       $a0, $a0, -0x6854
    ctx->r4 = ADD32(ctx->r4, -0X6854);
    setHudFlagBit40AndStoreArg(rdram, ctx);
        goto after_60;
    // 0x801048C0: addiu       $a0, $a0, -0x6854
    ctx->r4 = ADD32(ctx->r4, -0X6854);
    after_60:
    // 0x801048C4: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x801048C8: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x801048CC: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x801048D0: lwc1        $f22, -0x6840($at)
    ctx->f22.u32l = MEM_W(ctx->r1, -0X6840);
    // 0x801048D4: jal         0x800C7D1C
    // 0x801048D8: addiu       $a0, $zero, 0x23D
    ctx->r4 = ADD32(0, 0X23D);
    playObjectiveVoiceLine2(rdram, ctx);
        goto after_61;
    // 0x801048D8: addiu       $a0, $zero, 0x23D
    ctx->r4 = ADD32(0, 0X23D);
    after_61:
    // 0x801048DC: mfc1        $a1, $f22
    ctx->r5 = (int32_t)ctx->f22.u32l;
    // 0x801048E0: jal         0x800C7D1C
    // 0x801048E4: addiu       $a0, $zero, 0x155
    ctx->r4 = ADD32(0, 0X155);
    playObjectiveVoiceLine2(rdram, ctx);
        goto after_62;
    // 0x801048E4: addiu       $a0, $zero, 0x155
    ctx->r4 = ADD32(0, 0X155);
    after_62:
    // 0x801048E8: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x801048EC: jal         0x800C7D1C
    // 0x801048F0: addiu       $a0, $zero, 0x89
    ctx->r4 = ADD32(0, 0X89);
    playObjectiveVoiceLine2(rdram, ctx);
        goto after_63;
    // 0x801048F0: addiu       $a0, $zero, 0x89
    ctx->r4 = ADD32(0, 0X89);
    after_63:
    // 0x801048F4: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x801048F8: jal         0x800C7D1C
    // 0x801048FC: addiu       $a0, $zero, 0x103
    ctx->r4 = ADD32(0, 0X103);
    playObjectiveVoiceLine2(rdram, ctx);
        goto after_64;
    // 0x801048FC: addiu       $a0, $zero, 0x103
    ctx->r4 = ADD32(0, 0X103);
    after_64:
    // 0x80104900: mfc1        $a1, $f22
    ctx->r5 = (int32_t)ctx->f22.u32l;
    // 0x80104904: jal         0x800C7D1C
    // 0x80104908: addiu       $a0, $zero, 0x156
    ctx->r4 = ADD32(0, 0X156);
    playObjectiveVoiceLine2(rdram, ctx);
        goto after_65;
    // 0x80104908: addiu       $a0, $zero, 0x156
    ctx->r4 = ADD32(0, 0X156);
    after_65:
    // 0x8010490C: mfc1        $a1, $f22
    ctx->r5 = (int32_t)ctx->f22.u32l;
    // 0x80104910: jal         0x800C7D1C
    // 0x80104914: addiu       $a0, $zero, 0x149
    ctx->r4 = ADD32(0, 0X149);
    playObjectiveVoiceLine2(rdram, ctx);
        goto after_66;
    // 0x80104914: addiu       $a0, $zero, 0x149
    ctx->r4 = ADD32(0, 0X149);
    after_66:
L_80104918:
    // 0x80104918: jal         0x800C759C
    // 0x8010491C: addiu       $a0, $zero, 0x61
    ctx->r4 = ADD32(0, 0X61);
    getObjectiveBoolean(rdram, ctx);
        goto after_67;
    // 0x8010491C: addiu       $a0, $zero, 0x61
    ctx->r4 = ADD32(0, 0X61);
    after_67:
    // 0x80104920: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // 0x80104924: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80104928: bne         $s0, $v0, L_801049D0
    if (ctx->r16 != ctx->r2) {
        // 0x8010492C: nop
    
            goto L_801049D0;
    }
    // 0x8010492C: nop

    // 0x80104930: jal         0x800C759C
    // 0x80104934: addiu       $a0, $zero, 0x62
    ctx->r4 = ADD32(0, 0X62);
    getObjectiveBoolean(rdram, ctx);
        goto after_68;
    // 0x80104934: addiu       $a0, $zero, 0x62
    ctx->r4 = ADD32(0, 0X62);
    after_68:
    // 0x80104938: addu        $s1, $v0, $zero
    ctx->r17 = ADD32(ctx->r2, 0);
    // 0x8010493C: bne         $s1, $s0, L_801049D0
    if (ctx->r17 != ctx->r16) {
        // 0x80104940: nop
    
            goto L_801049D0;
    }
    // 0x80104940: nop

    // 0x80104944: jal         0x800C761C
    // 0x80104948: addiu       $a0, $zero, 0x28
    ctx->r4 = ADD32(0, 0X28);
    getObjectiveCount(rdram, ctx);
        goto after_69;
    // 0x80104948: addiu       $a0, $zero, 0x28
    ctx->r4 = ADD32(0, 0X28);
    after_69:
    // 0x8010494C: addiu       $v1, $zero, 0x4
    ctx->r3 = ADD32(0, 0X4);
    // 0x80104950: bne         $v0, $v1, L_801049D0
    if (ctx->r2 != ctx->r3) {
        // 0x80104954: lui         $v1, 0x8011
        ctx->r3 = S32(0X8011 << 16);
            goto L_801049D0;
    }
    // 0x80104954: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x80104958: lw          $v0, -0x2F60($v1)
    ctx->r2 = MEM_W(ctx->r3, -0X2F60);
    // 0x8010495C: bne         $v0, $zero, L_801049D0
    if (ctx->r2 != 0) {
        // 0x80104960: addiu       $a0, $zero, 0x32
        ctx->r4 = ADD32(0, 0X32);
            goto L_801049D0;
    }
    // 0x80104960: addiu       $a0, $zero, 0x32
    ctx->r4 = ADD32(0, 0X32);
    // 0x80104964: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80104968: jal         0x800C7540
    // 0x8010496C: sw          $s1, -0x2F60($v1)
    MEM_W(-0X2F60, ctx->r3) = ctx->r17;
    setObjectiveBoolean(rdram, ctx);
        goto after_70;
    // 0x8010496C: sw          $s1, -0x2F60($v1)
    MEM_W(-0X2F60, ctx->r3) = ctx->r17;
    after_70:
    // 0x80104970: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x80104974: jal         0x800C7884
    // 0x80104978: addiu       $a0, $a0, -0x6854
    ctx->r4 = ADD32(ctx->r4, -0X6854);
    setHudFlagBit40AndStoreArg(rdram, ctx);
        goto after_71;
    // 0x80104978: addiu       $a0, $a0, -0x6854
    ctx->r4 = ADD32(ctx->r4, -0X6854);
    after_71:
    // 0x8010497C: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x80104980: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80104984: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80104988: lwc1        $f22, -0x683C($at)
    ctx->f22.u32l = MEM_W(ctx->r1, -0X683C);
    // 0x8010498C: jal         0x800C7D1C
    // 0x80104990: addiu       $a0, $zero, 0x23D
    ctx->r4 = ADD32(0, 0X23D);
    playObjectiveVoiceLine2(rdram, ctx);
        goto after_72;
    // 0x80104990: addiu       $a0, $zero, 0x23D
    ctx->r4 = ADD32(0, 0X23D);
    after_72:
    // 0x80104994: mfc1        $a1, $f22
    ctx->r5 = (int32_t)ctx->f22.u32l;
    // 0x80104998: jal         0x800C7D1C
    // 0x8010499C: addiu       $a0, $zero, 0x155
    ctx->r4 = ADD32(0, 0X155);
    playObjectiveVoiceLine2(rdram, ctx);
        goto after_73;
    // 0x8010499C: addiu       $a0, $zero, 0x155
    ctx->r4 = ADD32(0, 0X155);
    after_73:
    // 0x801049A0: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x801049A4: jal         0x800C7D1C
    // 0x801049A8: addiu       $a0, $zero, 0x89
    ctx->r4 = ADD32(0, 0X89);
    playObjectiveVoiceLine2(rdram, ctx);
        goto after_74;
    // 0x801049A8: addiu       $a0, $zero, 0x89
    ctx->r4 = ADD32(0, 0X89);
    after_74:
    // 0x801049AC: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x801049B0: jal         0x800C7D1C
    // 0x801049B4: addiu       $a0, $zero, 0x103
    ctx->r4 = ADD32(0, 0X103);
    playObjectiveVoiceLine2(rdram, ctx);
        goto after_75;
    // 0x801049B4: addiu       $a0, $zero, 0x103
    ctx->r4 = ADD32(0, 0X103);
    after_75:
    // 0x801049B8: mfc1        $a1, $f22
    ctx->r5 = (int32_t)ctx->f22.u32l;
    // 0x801049BC: jal         0x800C7D1C
    // 0x801049C0: addiu       $a0, $zero, 0x156
    ctx->r4 = ADD32(0, 0X156);
    playObjectiveVoiceLine2(rdram, ctx);
        goto after_76;
    // 0x801049C0: addiu       $a0, $zero, 0x156
    ctx->r4 = ADD32(0, 0X156);
    after_76:
    // 0x801049C4: mfc1        $a1, $f22
    ctx->r5 = (int32_t)ctx->f22.u32l;
    // 0x801049C8: jal         0x800C7D1C
    // 0x801049CC: addiu       $a0, $zero, 0x149
    ctx->r4 = ADD32(0, 0X149);
    playObjectiveVoiceLine2(rdram, ctx);
        goto after_77;
    // 0x801049CC: addiu       $a0, $zero, 0x149
    ctx->r4 = ADD32(0, 0X149);
    after_77:
L_801049D0:
    // 0x801049D0: jal         0x800C761C
    // 0x801049D4: addiu       $a0, $zero, 0x63
    ctx->r4 = ADD32(0, 0X63);
    getObjectiveCount(rdram, ctx);
        goto after_78;
    // 0x801049D4: addiu       $a0, $zero, 0x63
    ctx->r4 = ADD32(0, 0X63);
    after_78:
    // 0x801049D8: slti        $v0, $v0, 0x3
    ctx->r2 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
    // 0x801049DC: bne         $v0, $zero, L_801049EC
    if (ctx->r2 != 0) {
        // 0x801049E0: nop
    
            goto L_801049EC;
    }
    // 0x801049E0: nop

    // 0x801049E4: jal         0x800C776C
    // 0x801049E8: nop

    setHudEnableBit8(rdram, ctx);
        goto after_79;
    // 0x801049E8: nop

    after_79:
L_801049EC:
    // 0x801049EC: lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X18);
    // 0x801049F0: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x801049F4: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x801049F8: ldc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X28);
    // 0x801049FC: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x80104A00: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x80104A04: jr          $ra
    // 0x80104A08: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80104A08: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void lv7_initializeObjectTracking(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80104A0C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80104A10: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80104A14: lwc1        $f12, -0x6838($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X6838);
    // 0x80104A18: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80104A1C: sw          $zero, -0x2F70($v0)
    MEM_W(-0X2F70, ctx->r2) = 0;
    // 0x80104A20: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80104A24: sw          $zero, -0x2F6C($v0)
    MEM_W(-0X2F6C, ctx->r2) = 0;
    // 0x80104A28: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80104A2C: sw          $zero, -0x2F68($v0)
    MEM_W(-0X2F68, ctx->r2) = 0;
    // 0x80104A30: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80104A34: sw          $zero, -0x2F64($v0)
    MEM_W(-0X2F64, ctx->r2) = 0;
    // 0x80104A38: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80104A3C: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80104A40: jal         0x800C7CEC
    // 0x80104A44: sw          $zero, -0x2F60($v0)
    MEM_W(-0X2F60, ctx->r2) = 0;
    setLevelObjectTrackingScalar(rdram, ctx);
        goto after_0;
    // 0x80104A44: sw          $zero, -0x2F60($v0)
    MEM_W(-0X2F60, ctx->r2) = 0;
    after_0:
    // 0x80104A48: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80104A4C: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x80104A50: jr          $ra
    // 0x80104A54: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80104A54: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void lv7_objectiveSlot1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80104A58: jr          $ra
    // 0x80104A5C: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    return;
    // 0x80104A5C: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
;}
RECOMP_FUNC void lv7_calculateFriendliesSaved(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80104A60: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80104A64: addiu       $a0, $zero, 0x80
    ctx->r4 = ADD32(0, 0X80);
    // 0x80104A68: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80104A6C: jal         0x800C761C
    // 0x80104A70: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    getObjectiveCount(rdram, ctx);
        goto after_0;
    // 0x80104A70: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    after_0:
    // 0x80104A74: addiu       $a0, $zero, 0x80
    ctx->r4 = ADD32(0, 0X80);
    // 0x80104A78: jal         0x800C761C
    // 0x80104A7C: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    getObjectiveCount(rdram, ctx);
        goto after_1;
    // 0x80104A7C: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    after_1:
    // 0x80104A80: addu        $s0, $s0, $v0
    ctx->r16 = ADD32(ctx->r16, ctx->r2);
    // 0x80104A84: jal         0x800C77B0
    // 0x80104A88: negu        $a0, $s0
    ctx->r4 = SUB32(0, ctx->r16);
    setFriendliesSaved(rdram, ctx);
        goto after_2;
    // 0x80104A88: negu        $a0, $s0
    ctx->r4 = SUB32(0, ctx->r16);
    after_2:
    // 0x80104A8C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80104A90: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80104A94: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x80104A98: jr          $ra
    // 0x80104A9C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80104A9C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void lv8_checkComplexObjectives(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80104AA0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80104AA4: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x80104AA8: mov.s       $f22, $f12
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 12);
    ctx->f22.fl = ctx->f12.fl;
    // 0x80104AAC: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x80104AB0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80104AB4: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80104AB8: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x80104ABC: jal         0x800C78A0
    // 0x80104AC0: addiu       $a0, $a0, -0x6818
    ctx->r4 = ADD32(ctx->r4, -0X6818);
    calculateDatItemDistanceToPlayer(rdram, ctx);
        goto after_0;
    // 0x80104AC0: addiu       $a0, $a0, -0x6818
    ctx->r4 = ADD32(ctx->r4, -0X6818);
    after_0:
    // 0x80104AC4: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80104AC8: lwc1        $f2, -0x67F4($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X67F4);
    // 0x80104ACC: c.le.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl <= ctx->f2.fl;
    // 0x80104AD0: nop

    // 0x80104AD4: bc1f        L_80104B28
    if (!c1cs) {
        // 0x80104AD8: lui         $v1, 0x8011
        ctx->r3 = S32(0X8011 << 16);
            goto L_80104B28;
    }
    // 0x80104AD8: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x80104ADC: lw          $v0, -0x2F50($v1)
    ctx->r2 = MEM_W(ctx->r3, -0X2F50);
    // 0x80104AE0: bnel        $v0, $zero, L_80104B2C
    if (ctx->r2 != 0) {
        // 0x80104AE4: lui         $a0, 0x800B
        ctx->r4 = S32(0X800B << 16);
            goto L_80104B2C;
    }
    goto skip_0;
    // 0x80104AE4: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    skip_0:
    // 0x80104AE8: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    // 0x80104AEC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80104AF0: addu        $s0, $a1, $zero
    ctx->r16 = ADD32(ctx->r5, 0);
    // 0x80104AF4: jal         0x800C7540
    // 0x80104AF8: sw          $s0, -0x2F50($v1)
    MEM_W(-0X2F50, ctx->r3) = ctx->r16;
    setObjectiveBoolean(rdram, ctx);
        goto after_1;
    // 0x80104AF8: sw          $s0, -0x2F50($v1)
    MEM_W(-0X2F50, ctx->r3) = ctx->r16;
    after_1:
    // 0x80104AFC: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x80104B00: jal         0x800C7660
    // 0x80104B04: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    setObjectiveHiddenFlag(rdram, ctx);
        goto after_2;
    // 0x80104B04: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
    // 0x80104B08: addiu       $a0, $zero, 0x15A
    ctx->r4 = ADD32(0, 0X15A);
    // 0x80104B0C: jal         0x800C7D1C
    // 0x80104B10: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    playObjectiveVoiceLine2(rdram, ctx);
        goto after_3;
    // 0x80104B10: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_3:
    // 0x80104B14: lui         $a1, 0x4000
    ctx->r5 = S32(0X4000 << 16);
    // 0x80104B18: jal         0x800C7D1C
    // 0x80104B1C: addiu       $a0, $zero, 0x266
    ctx->r4 = ADD32(0, 0X266);
    playObjectiveVoiceLine2(rdram, ctx);
        goto after_4;
    // 0x80104B1C: addiu       $a0, $zero, 0x266
    ctx->r4 = ADD32(0, 0X266);
    after_4:
    // 0x80104B20: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80104B24: sw          $s0, -0x2F3C($v0)
    MEM_W(-0X2F3C, ctx->r2) = ctx->r16;
L_80104B28:
    // 0x80104B28: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
L_80104B2C:
    // 0x80104B2C: jal         0x800C78A0
    // 0x80104B30: addiu       $a0, $a0, -0x6808
    ctx->r4 = ADD32(ctx->r4, -0X6808);
    calculateDatItemDistanceToPlayer(rdram, ctx);
        goto after_5;
    // 0x80104B30: addiu       $a0, $a0, -0x6808
    ctx->r4 = ADD32(ctx->r4, -0X6808);
    after_5:
    // 0x80104B34: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80104B38: lwc1        $f2, -0x67F0($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X67F0);
    // 0x80104B3C: c.le.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl <= ctx->f2.fl;
    // 0x80104B40: nop

    // 0x80104B44: bc1f        L_80104B90
    if (!c1cs) {
        // 0x80104B48: lui         $v1, 0x8011
        ctx->r3 = S32(0X8011 << 16);
            goto L_80104B90;
    }
    // 0x80104B48: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x80104B4C: lw          $v0, -0x2F4C($v1)
    ctx->r2 = MEM_W(ctx->r3, -0X2F4C);
    // 0x80104B50: bne         $v0, $zero, L_80104B90
    if (ctx->r2 != 0) {
        // 0x80104B54: addiu       $a0, $zero, 0x6
        ctx->r4 = ADD32(0, 0X6);
            goto L_80104B90;
    }
    // 0x80104B54: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    // 0x80104B58: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80104B5C: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x80104B60: addu        $v0, $a1, $zero
    ctx->r2 = ADD32(ctx->r5, 0);
    // 0x80104B64: jal         0x800C7540
    // 0x80104B68: sw          $v0, -0x2F4C($v1)
    MEM_W(-0X2F4C, ctx->r3) = ctx->r2;
    setObjectiveBoolean(rdram, ctx);
        goto after_6;
    // 0x80104B68: sw          $v0, -0x2F4C($v1)
    MEM_W(-0X2F4C, ctx->r3) = ctx->r2;
    after_6:
    // 0x80104B6C: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80104B70: jal         0x800C7D1C
    // 0x80104B74: addiu       $a0, $zero, 0x158
    ctx->r4 = ADD32(0, 0X158);
    playObjectiveVoiceLine2(rdram, ctx);
        goto after_7;
    // 0x80104B74: addiu       $a0, $zero, 0x158
    ctx->r4 = ADD32(0, 0X158);
    after_7:
    // 0x80104B78: lui         $a1, 0x4000
    ctx->r5 = S32(0X4000 << 16);
    // 0x80104B7C: jal         0x800C7D1C
    // 0x80104B80: addiu       $a0, $zero, 0x265
    ctx->r4 = ADD32(0, 0X265);
    playObjectiveVoiceLine2(rdram, ctx);
        goto after_8;
    // 0x80104B80: addiu       $a0, $zero, 0x265
    ctx->r4 = ADD32(0, 0X265);
    after_8:
    // 0x80104B84: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80104B88: jal         0x800C7D1C
    // 0x80104B8C: addiu       $a0, $zero, 0xE2
    ctx->r4 = ADD32(0, 0XE2);
    playObjectiveVoiceLine2(rdram, ctx);
        goto after_9;
    // 0x80104B8C: addiu       $a0, $zero, 0xE2
    ctx->r4 = ADD32(0, 0XE2);
    after_9:
L_80104B90:
    // 0x80104B90: jal         0x800C759C
    // 0x80104B94: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    getObjectiveBoolean(rdram, ctx);
        goto after_10;
    // 0x80104B94: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    after_10:
    // 0x80104B98: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x80104B9C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80104BA0: bne         $v1, $v0, L_80104BF8
    if (ctx->r3 != ctx->r2) {
        // 0x80104BA4: lui         $a0, 0x8011
        ctx->r4 = S32(0X8011 << 16);
            goto L_80104BF8;
    }
    // 0x80104BA4: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x80104BA8: lw          $v0, -0x2F48($a0)
    ctx->r2 = MEM_W(ctx->r4, -0X2F48);
    // 0x80104BAC: bne         $v0, $zero, L_80104BF8
    if (ctx->r2 != 0) {
        // 0x80104BB0: nop
    
            goto L_80104BF8;
    }
    // 0x80104BB0: nop

    // 0x80104BB4: jal         0x800C7738
    // 0x80104BB8: sw          $v1, -0x2F48($a0)
    MEM_W(-0X2F48, ctx->r4) = ctx->r3;
    setHudEnableBit4(rdram, ctx);
        goto after_11;
    // 0x80104BB8: sw          $v1, -0x2F48($a0)
    MEM_W(-0X2F48, ctx->r4) = ctx->r3;
    after_11:
    // 0x80104BBC: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x80104BC0: jal         0x800C7884
    // 0x80104BC4: addiu       $a0, $a0, -0x67FC
    ctx->r4 = ADD32(ctx->r4, -0X67FC);
    setHudFlagBit40AndStoreArg(rdram, ctx);
        goto after_12;
    // 0x80104BC4: addiu       $a0, $a0, -0x67FC
    ctx->r4 = ADD32(ctx->r4, -0X67FC);
    after_12:
    // 0x80104BC8: addiu       $a0, $zero, 0x267
    ctx->r4 = ADD32(0, 0X267);
    // 0x80104BCC: jal         0x800C7D1C
    // 0x80104BD0: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    playObjectiveVoiceLine2(rdram, ctx);
        goto after_13;
    // 0x80104BD0: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_13:
    // 0x80104BD4: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x80104BD8: addiu       $a0, $a0, -0x6818
    ctx->r4 = ADD32(ctx->r4, -0X6818);
    // 0x80104BDC: lui         $a1, 0x3D4C
    ctx->r5 = S32(0X3D4C << 16);
    // 0x80104BE0: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x80104BE4: lui         $a3, 0x40A0
    ctx->r7 = S32(0X40A0 << 16);
    // 0x80104BE8: jal         0x800C7978
    // 0x80104BEC: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    func_800C7978(rdram, ctx);
        goto after_14;
    // 0x80104BEC: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    after_14:
    // 0x80104BF0: jal         0x800C7D98
    // 0x80104BF4: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    triggerSoundCueByType(rdram, ctx);
        goto after_15;
    // 0x80104BF4: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    after_15:
L_80104BF8:
    // 0x80104BF8: jal         0x800C761C
    // 0x80104BFC: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    getObjectiveCount(rdram, ctx);
        goto after_16;
    // 0x80104BFC: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_16:
    // 0x80104C00: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x80104C04: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80104C08: bne         $v1, $v0, L_80104C3C
    if (ctx->r3 != ctx->r2) {
        // 0x80104C0C: lui         $a0, 0x8011
        ctx->r4 = S32(0X8011 << 16);
            goto L_80104C3C;
    }
    // 0x80104C0C: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x80104C10: lw          $v0, -0x2F48($a0)
    ctx->r2 = MEM_W(ctx->r4, -0X2F48);
    // 0x80104C14: bne         $v0, $zero, L_80104C3C
    if (ctx->r2 != 0) {
        // 0x80104C18: nop
    
            goto L_80104C3C;
    }
    // 0x80104C18: nop

    // 0x80104C1C: jal         0x800C7738
    // 0x80104C20: sw          $v1, -0x2F48($a0)
    MEM_W(-0X2F48, ctx->r4) = ctx->r3;
    setHudEnableBit4(rdram, ctx);
        goto after_17;
    // 0x80104C20: sw          $v1, -0x2F48($a0)
    MEM_W(-0X2F48, ctx->r4) = ctx->r3;
    after_17:
    // 0x80104C24: addiu       $a0, $zero, 0x15F
    ctx->r4 = ADD32(0, 0X15F);
    // 0x80104C28: jal         0x800C7D1C
    // 0x80104C2C: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    playObjectiveVoiceLine2(rdram, ctx);
        goto after_18;
    // 0x80104C2C: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_18:
    // 0x80104C30: lui         $a1, 0x4000
    ctx->r5 = S32(0X4000 << 16);
    // 0x80104C34: jal         0x800C7D1C
    // 0x80104C38: addiu       $a0, $zero, 0xFD
    ctx->r4 = ADD32(0, 0XFD);
    playObjectiveVoiceLine2(rdram, ctx);
        goto after_19;
    // 0x80104C38: addiu       $a0, $zero, 0xFD
    ctx->r4 = ADD32(0, 0XFD);
    after_19:
L_80104C3C:
    // 0x80104C3C: jal         0x800C761C
    // 0x80104C40: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    getObjectiveCount(rdram, ctx);
        goto after_20;
    // 0x80104C40: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    after_20:
    // 0x80104C44: addiu       $v1, $zero, 0x7
    ctx->r3 = ADD32(0, 0X7);
    // 0x80104C48: bne         $v0, $v1, L_80104CA8
    if (ctx->r2 != ctx->r3) {
        // 0x80104C4C: lui         $v1, 0x8011
        ctx->r3 = S32(0X8011 << 16);
            goto L_80104CA8;
    }
    // 0x80104C4C: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x80104C50: lw          $v0, -0x2F44($v1)
    ctx->r2 = MEM_W(ctx->r3, -0X2F44);
    // 0x80104C54: bne         $v0, $zero, L_80104CA8
    if (ctx->r2 != 0) {
        // 0x80104C58: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80104CA8;
    }
    // 0x80104C58: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80104C5C: jal         0x800C776C
    // 0x80104C60: sw          $v0, -0x2F44($v1)
    MEM_W(-0X2F44, ctx->r3) = ctx->r2;
    setHudEnableBit8(rdram, ctx);
        goto after_21;
    // 0x80104C60: sw          $v0, -0x2F44($v1)
    MEM_W(-0X2F44, ctx->r3) = ctx->r2;
    after_21:
    // 0x80104C64: jal         0x800C76B0
    // 0x80104C68: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    activateObjectiveCompleteFlag(rdram, ctx);
        goto after_22;
    // 0x80104C68: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_22:
    // 0x80104C6C: jal         0x800C76B0
    // 0x80104C70: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    activateObjectiveCompleteFlag(rdram, ctx);
        goto after_23;
    // 0x80104C70: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_23:
    // 0x80104C74: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x80104C78: addiu       $a0, $a0, -0x6818
    ctx->r4 = ADD32(ctx->r4, -0X6818);
    // 0x80104C7C: lui         $a1, 0x3CCC
    ctx->r5 = S32(0X3CCC << 16);
    // 0x80104C80: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x80104C84: lui         $a3, 0x40A0
    ctx->r7 = S32(0X40A0 << 16);
    // 0x80104C88: jal         0x800C7978
    // 0x80104C8C: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    func_800C7978(rdram, ctx);
        goto after_24;
    // 0x80104C8C: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    after_24:
    // 0x80104C90: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    // 0x80104C94: jal         0x800C7D1C
    // 0x80104C98: addiu       $a0, $zero, 0x11E
    ctx->r4 = ADD32(0, 0X11E);
    playObjectiveVoiceLine2(rdram, ctx);
        goto after_25;
    // 0x80104C98: addiu       $a0, $zero, 0x11E
    ctx->r4 = ADD32(0, 0X11E);
    after_25:
    // 0x80104C9C: addiu       $a0, $zero, 0x277
    ctx->r4 = ADD32(0, 0X277);
    // 0x80104CA0: jal         0x800C7D1C
    // 0x80104CA4: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    playObjectiveVoiceLine2(rdram, ctx);
        goto after_26;
    // 0x80104CA4: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_26:
L_80104CA8:
    // 0x80104CA8: jal         0x80104CCC
    // 0x80104CAC: mov.s       $f12, $f22
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    ctx->f12.fl = ctx->f22.fl;
    func_80104CCC(rdram, ctx);
        goto after_27;
    // 0x80104CAC: mov.s       $f12, $f22
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    ctx->f12.fl = ctx->f22.fl;
    after_27:
    // 0x80104CB0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80104CB4: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80104CB8: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x80104CBC: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x80104CC0: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x80104CC4: jr          $ra
    // 0x80104CC8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80104CC8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_80104CCC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80104CCC: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80104CD0: lw          $v0, -0x2F3C($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X2F3C);
    // 0x80104CD4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80104CD8: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x80104CDC: mov.s       $f20, $f12
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 12);
    ctx->f20.fl = ctx->f12.fl;
    // 0x80104CE0: beq         $v0, $zero, L_80104D7C
    if (ctx->r2 == 0) {
        // 0x80104CE4: sw          $ra, 0x10($sp)
        MEM_W(0X10, ctx->r29) = ctx->r31;
            goto L_80104D7C;
    }
    // 0x80104CE4: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80104CE8: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x80104CEC: jal         0x800C78A0
    // 0x80104CF0: addiu       $a0, $a0, -0x67EC
    ctx->r4 = ADD32(ctx->r4, -0X67EC);
    calculateDatItemDistanceToPlayer(rdram, ctx);
        goto after_0;
    // 0x80104CF0: addiu       $a0, $a0, -0x67EC
    ctx->r4 = ADD32(ctx->r4, -0X67EC);
    after_0:
    // 0x80104CF4: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80104CF8: lwc1        $f2, -0x67DC($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X67DC);
    // 0x80104CFC: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x80104D00: nop

    // 0x80104D04: bc1f        L_80104D40
    if (!c1cs) {
        // 0x80104D08: lui         $v1, 0x8011
        ctx->r3 = S32(0X8011 << 16);
            goto L_80104D40;
    }
    // 0x80104D08: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x80104D0C: lw          $v0, -0x2F40($v1)
    ctx->r2 = MEM_W(ctx->r3, -0X2F40);
    // 0x80104D10: bne         $v0, $zero, L_80104D2C
    if (ctx->r2 != 0) {
        // 0x80104D14: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80104D2C;
    }
    // 0x80104D14: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80104D18: sw          $v0, -0x2F40($v1)
    MEM_W(-0X2F40, ctx->r3) = ctx->r2;
    // 0x80104D1C: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x80104D20: addiu       $a0, $a0, -0x6830
    ctx->r4 = ADD32(ctx->r4, -0X6830);
    // 0x80104D24: jal         0x800C7D60
    // 0x80104D28: addu        $a1, $v0, $zero
    ctx->r5 = ADD32(ctx->r2, 0);
    delegateToLevelStageTick(rdram, ctx);
        goto after_1;
    // 0x80104D28: addu        $a1, $v0, $zero
    ctx->r5 = ADD32(ctx->r2, 0);
    after_1:
L_80104D2C:
    // 0x80104D2C: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80104D30: lwc1        $f0, -0x67D8($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X67D8);
    // 0x80104D34: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80104D38: j           L_80104D7C
    // 0x80104D3C: swc1        $f0, -0x2F38($v0)
    MEM_W(-0X2F38, ctx->r2) = ctx->f0.u32l;
        goto L_80104D7C;
    // 0x80104D3C: swc1        $f0, -0x2F38($v0)
    MEM_W(-0X2F38, ctx->r2) = ctx->f0.u32l;
L_80104D40:
    // 0x80104D40: lw          $v0, -0x2F40($v1)
    ctx->r2 = MEM_W(ctx->r3, -0X2F40);
    // 0x80104D44: beq         $v0, $zero, L_80104D7C
    if (ctx->r2 == 0) {
        // 0x80104D48: lui         $v0, 0x8011
        ctx->r2 = S32(0X8011 << 16);
            goto L_80104D7C;
    }
    // 0x80104D48: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80104D4C: lwc1        $f0, -0x2F38($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, -0X2F38);
    // 0x80104D50: sub.s       $f0, $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f20.fl;
    // 0x80104D54: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x80104D58: c.le.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl <= ctx->f2.fl;
    // 0x80104D5C: nop

    // 0x80104D60: bc1f        L_80104D7C
    if (!c1cs) {
        // 0x80104D64: swc1        $f0, -0x2F38($v0)
        MEM_W(-0X2F38, ctx->r2) = ctx->f0.u32l;
            goto L_80104D7C;
    }
    // 0x80104D64: swc1        $f0, -0x2F38($v0)
    MEM_W(-0X2F38, ctx->r2) = ctx->f0.u32l;
    // 0x80104D68: sw          $zero, -0x2F40($v1)
    MEM_W(-0X2F40, ctx->r3) = 0;
    // 0x80104D6C: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x80104D70: addiu       $a0, $a0, -0x6830
    ctx->r4 = ADD32(ctx->r4, -0X6830);
    // 0x80104D74: jal         0x800C7D60
    // 0x80104D78: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    delegateToLevelStageTick(rdram, ctx);
        goto after_2;
    // 0x80104D78: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_2:
L_80104D7C:
    // 0x80104D7C: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80104D80: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x80104D84: jr          $ra
    // 0x80104D88: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80104D88: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void lv8_initializeObjectTracking(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80104D8C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80104D90: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x80104D94: addiu       $a0, $a0, 0x4EC8
    ctx->r4 = ADD32(ctx->r4, 0X4EC8);
    // 0x80104D98: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    // 0x80104D9C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80104DA0: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // 0x80104DA4: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80104DA8: sw          $zero, -0x2F50($v0)
    MEM_W(-0X2F50, ctx->r2) = 0;
    // 0x80104DAC: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80104DB0: sw          $zero, -0x2F4C($v0)
    MEM_W(-0X2F4C, ctx->r2) = 0;
    // 0x80104DB4: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80104DB8: sw          $zero, -0x2F48($v0)
    MEM_W(-0X2F48, ctx->r2) = 0;
    // 0x80104DBC: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80104DC0: sw          $zero, -0x2F44($v0)
    MEM_W(-0X2F44, ctx->r2) = 0;
    // 0x80104DC4: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80104DC8: sw          $zero, -0x2F40($v0)
    MEM_W(-0X2F40, ctx->r2) = 0;
    // 0x80104DCC: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80104DD0: sw          $zero, -0x2F3C($v0)
    MEM_W(-0X2F3C, ctx->r2) = 0;
    // 0x80104DD4: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80104DD8: sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // 0x80104DDC: sw          $zero, -0x2F38($v0)
    MEM_W(-0X2F38, ctx->r2) = 0;
    // 0x80104DE0: jal         0x800C7830
    // 0x80104DE4: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    addBooleanCountHandleWrapper(rdram, ctx);
        goto after_0;
    // 0x80104DE4: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_0:
    // 0x80104DE8: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x80104DEC: addiu       $a0, $a0, 0x4EE4
    ctx->r4 = ADD32(ctx->r4, 0X4EE4);
    // 0x80104DF0: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    // 0x80104DF4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80104DF8: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // 0x80104DFC: jal         0x800C7830
    // 0x80104E00: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    addBooleanCountHandleWrapper(rdram, ctx);
        goto after_1;
    // 0x80104E00: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_1:
    // 0x80104E04: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x80104E08: addiu       $a0, $a0, 0x4F00
    ctx->r4 = ADD32(ctx->r4, 0X4F00);
    // 0x80104E0C: addiu       $a1, $zero, 0xE
    ctx->r5 = ADD32(0, 0XE);
    // 0x80104E10: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80104E14: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // 0x80104E18: jal         0x800C7830
    // 0x80104E1C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    addBooleanCountHandleWrapper(rdram, ctx);
        goto after_2;
    // 0x80104E1C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_2:
    // 0x80104E20: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x80104E24: addiu       $a0, $a0, 0x4F1C
    ctx->r4 = ADD32(ctx->r4, 0X4F1C);
    // 0x80104E28: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80104E2C: addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    // 0x80104E30: addiu       $a3, $zero, 0x5
    ctx->r7 = ADD32(0, 0X5);
    // 0x80104E34: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x80104E38: jal         0x800C7830
    // 0x80104E3C: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    addBooleanCountHandleWrapper(rdram, ctx);
        goto after_3;
    // 0x80104E3C: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    after_3:
    // 0x80104E40: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80104E44: jal         0x800C7660
    // 0x80104E48: addu        $a1, $a0, $zero
    ctx->r5 = ADD32(ctx->r4, 0);
    setObjectiveHiddenFlag(rdram, ctx);
        goto after_4;
    // 0x80104E48: addu        $a1, $a0, $zero
    ctx->r5 = ADD32(ctx->r4, 0);
    after_4:
    // 0x80104E4C: jal         0x80104F6C
    // 0x80104E50: nop

    func_80104F6C(rdram, ctx);
        goto after_5;
    // 0x80104E50: nop

    after_5:
    // 0x80104E54: lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X18);
    // 0x80104E58: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x80104E5C: jr          $ra
    // 0x80104E60: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80104E60: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void lv8_objectiveSlot1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80104E64: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80104E68: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80104E6C: sw          $zero, -0x2F38($v0)
    MEM_W(-0X2F38, ctx->r2) = 0;
    // 0x80104E70: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80104E74: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x80104E78: addiu       $a0, $a0, -0x6830
    ctx->r4 = ADD32(ctx->r4, -0X6830);
    // 0x80104E7C: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80104E80: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80104E84: jal         0x800C7D7C
    // 0x80104E88: sw          $zero, -0x2F40($v0)
    MEM_W(-0X2F40, ctx->r2) = 0;
    func_800C7D7C(rdram, ctx);
        goto after_0;
    // 0x80104E88: sw          $zero, -0x2F40($v0)
    MEM_W(-0X2F40, ctx->r2) = 0;
    after_0:
    // 0x80104E8C: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80104E90: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x80104E94: jr          $ra
    // 0x80104E98: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80104E98: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void lv8_calculateFriendliesSaved(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80104E9C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80104EA0: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80104EA4: jal         0x800C761C
    // 0x80104EA8: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    getObjectiveCount(rdram, ctx);
        goto after_0;
    // 0x80104EA8: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    after_0:
    // 0x80104EAC: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    // 0x80104EB0: jal         0x800C77B0
    // 0x80104EB4: subu        $a0, $a0, $v0
    ctx->r4 = SUB32(ctx->r4, ctx->r2);
    setFriendliesSaved(rdram, ctx);
        goto after_1;
    // 0x80104EB4: subu        $a0, $a0, $v0
    ctx->r4 = SUB32(ctx->r4, ctx->r2);
    after_1:
    // 0x80104EB8: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80104EBC: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x80104EC0: jr          $ra
    // 0x80104EC4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80104EC4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void playVoice_0x107(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80104EC8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80104ECC: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80104ED0: jal         0x800C7CF8
    // 0x80104ED4: addiu       $a0, $zero, 0x107
    ctx->r4 = ADD32(0, 0X107);
    playObjectiveVoiceLine1(rdram, ctx);
        goto after_0;
    // 0x80104ED4: addiu       $a0, $zero, 0x107
    ctx->r4 = ADD32(0, 0X107);
    after_0:
    // 0x80104ED8: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80104EDC: jr          $ra
    // 0x80104EE0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80104EE0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void playVoice_0xCC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80104EE4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80104EE8: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80104EEC: jal         0x800C7CF8
    // 0x80104EF0: addiu       $a0, $zero, 0xCC
    ctx->r4 = ADD32(0, 0XCC);
    playObjectiveVoiceLine1(rdram, ctx);
        goto after_0;
    // 0x80104EF0: addiu       $a0, $zero, 0xCC
    ctx->r4 = ADD32(0, 0XCC);
    after_0:
    // 0x80104EF4: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80104EF8: jr          $ra
    // 0x80104EFC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80104EFC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void playVoice_0xE4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80104F00: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80104F04: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80104F08: jal         0x800C7CF8
    // 0x80104F0C: addiu       $a0, $zero, 0xE4
    ctx->r4 = ADD32(0, 0XE4);
    playObjectiveVoiceLine1(rdram, ctx);
        goto after_0;
    // 0x80104F0C: addiu       $a0, $zero, 0xE4
    ctx->r4 = ADD32(0, 0XE4);
    after_0:
    // 0x80104F10: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80104F14: jr          $ra
    // 0x80104F18: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80104F18: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void lv8_playPairedDialogue(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80104F1C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80104F20: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x80104F24: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x80104F28: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80104F2C: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80104F30: jal         0x800C7D1C
    // 0x80104F34: addiu       $a0, $zero, 0x26C
    ctx->r4 = ADD32(0, 0X26C);
    playObjectiveVoiceLine2(rdram, ctx);
        goto after_0;
    // 0x80104F34: addiu       $a0, $zero, 0x26C
    ctx->r4 = ADD32(0, 0X26C);
    after_0:
    // 0x80104F38: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80104F3C: jal         0x800C7D1C
    // 0x80104F40: addiu       $a0, $zero, 0x15C
    ctx->r4 = ADD32(0, 0X15C);
    playObjectiveVoiceLine2(rdram, ctx);
        goto after_1;
    // 0x80104F40: addiu       $a0, $zero, 0x15C
    ctx->r4 = ADD32(0, 0X15C);
    after_1:
    // 0x80104F44: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x80104F48: addiu       $a0, $a0, -0x6818
    ctx->r4 = ADD32(ctx->r4, -0X6818);
    // 0x80104F4C: lui         $a1, 0x3F00
    ctx->r5 = S32(0X3F00 << 16);
    // 0x80104F50: lui         $a3, 0x40A0
    ctx->r7 = S32(0X40A0 << 16);
    // 0x80104F54: jal         0x800C7978
    // 0x80104F58: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    func_800C7978(rdram, ctx);
        goto after_2;
    // 0x80104F58: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    after_2:
    // 0x80104F5C: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80104F60: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x80104F64: jr          $ra
    // 0x80104F68: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80104F68: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_80104F6C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80104F6C: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80104F70: sw          $zero, -0x2F40($v0)
    MEM_W(-0X2F40, ctx->r2) = 0;
    // 0x80104F74: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80104F78: jr          $ra
    // 0x80104F7C: sw          $zero, -0x2F3C($v0)
    MEM_W(-0X2F3C, ctx->r2) = 0;
    return;
    // 0x80104F7C: sw          $zero, -0x2F3C($v0)
    MEM_W(-0X2F3C, ctx->r2) = 0;
;}
RECOMP_FUNC void lv9_initializeObjectTracking(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80104F80: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80104F84: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80104F88: lwc1        $f12, -0x67D0($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X67D0);
    // 0x80104F8C: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80104F90: sw          $zero, -0x2F30($v0)
    MEM_W(-0X2F30, ctx->r2) = 0;
    // 0x80104F94: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80104F98: sw          $zero, -0x2F2C($v0)
    MEM_W(-0X2F2C, ctx->r2) = 0;
    // 0x80104F9C: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80104FA0: sw          $zero, -0x2F28($v0)
    MEM_W(-0X2F28, ctx->r2) = 0;
    // 0x80104FA4: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80104FA8: sw          $zero, -0x2F24($v0)
    MEM_W(-0X2F24, ctx->r2) = 0;
    // 0x80104FAC: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80104FB0: sw          $ra, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r31;
    // 0x80104FB4: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80104FB8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80104FBC: jal         0x800C7CEC
    // 0x80104FC0: sw          $zero, -0x2F20($v0)
    MEM_W(-0X2F20, ctx->r2) = 0;
    setLevelObjectTrackingScalar(rdram, ctx);
        goto after_0;
    // 0x80104FC0: sw          $zero, -0x2F20($v0)
    MEM_W(-0X2F20, ctx->r2) = 0;
    after_0:
    // 0x80104FC4: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x80104FC8: addiu       $a0, $a0, 0x5304
    ctx->r4 = ADD32(ctx->r4, 0X5304);
    // 0x80104FCC: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80104FD0: addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    // 0x80104FD4: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x80104FD8: addu        $s1, $a3, $zero
    ctx->r17 = ADD32(ctx->r7, 0);
    // 0x80104FDC: jal         0x800C7830
    // 0x80104FE0: sw          $s1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r17;
    addBooleanCountHandleWrapper(rdram, ctx);
        goto after_1;
    // 0x80104FE0: sw          $s1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r17;
    after_1:
    // 0x80104FE4: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x80104FE8: addiu       $a0, $a0, 0x539C
    ctx->r4 = ADD32(ctx->r4, 0X539C);
    // 0x80104FEC: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80104FF0: addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    // 0x80104FF4: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    // 0x80104FF8: jal         0x800C7830
    // 0x80104FFC: sw          $s1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r17;
    addBooleanCountHandleWrapper(rdram, ctx);
        goto after_2;
    // 0x80104FFC: sw          $s1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r17;
    after_2:
    // 0x80105000: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x80105004: addiu       $a0, $a0, 0x53C8
    ctx->r4 = ADD32(ctx->r4, 0X53C8);
    // 0x80105008: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x8010500C: addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    // 0x80105010: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    // 0x80105014: jal         0x800C7830
    // 0x80105018: sw          $s1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r17;
    addBooleanCountHandleWrapper(rdram, ctx);
        goto after_3;
    // 0x80105018: sw          $s1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r17;
    after_3:
    // 0x8010501C: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x80105020: addiu       $a0, $a0, 0x549C
    ctx->r4 = ADD32(ctx->r4, 0X549C);
    // 0x80105024: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80105028: addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    // 0x8010502C: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    // 0x80105030: jal         0x800C7830
    // 0x80105034: sw          $s1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r17;
    addBooleanCountHandleWrapper(rdram, ctx);
        goto after_4;
    // 0x80105034: sw          $s1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r17;
    after_4:
    // 0x80105038: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x8010503C: addiu       $a0, $a0, 0x552C
    ctx->r4 = ADD32(ctx->r4, 0X552C);
    // 0x80105040: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    // 0x80105044: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80105048: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // 0x8010504C: jal         0x800C7830
    // 0x80105050: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    addBooleanCountHandleWrapper(rdram, ctx);
        goto after_5;
    // 0x80105050: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_5:
    // 0x80105054: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x80105058: addiu       $a0, $a0, 0x556C
    ctx->r4 = ADD32(ctx->r4, 0X556C);
    // 0x8010505C: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x80105060: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80105064: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // 0x80105068: jal         0x800C7830
    // 0x8010506C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    addBooleanCountHandleWrapper(rdram, ctx);
        goto after_6;
    // 0x8010506C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_6:
    // 0x80105070: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x80105074: addiu       $a0, $a0, 0x55AC
    ctx->r4 = ADD32(ctx->r4, 0X55AC);
    // 0x80105078: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    // 0x8010507C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80105080: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // 0x80105084: jal         0x800C7830
    // 0x80105088: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    addBooleanCountHandleWrapper(rdram, ctx);
        goto after_7;
    // 0x80105088: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_7:
    // 0x8010508C: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x80105090: addiu       $a0, $a0, 0x55E0
    ctx->r4 = ADD32(ctx->r4, 0X55E0);
    // 0x80105094: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    // 0x80105098: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8010509C: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // 0x801050A0: jal         0x800C7830
    // 0x801050A4: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    addBooleanCountHandleWrapper(rdram, ctx);
        goto after_8;
    // 0x801050A4: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_8:
    // 0x801050A8: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x801050AC: addiu       $a0, $a0, 0x5600
    ctx->r4 = ADD32(ctx->r4, 0X5600);
    // 0x801050B0: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    // 0x801050B4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x801050B8: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // 0x801050BC: jal         0x800C7830
    // 0x801050C0: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    addBooleanCountHandleWrapper(rdram, ctx);
        goto after_9;
    // 0x801050C0: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_9:
    // 0x801050C4: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x801050C8: addiu       $a0, $a0, 0x5660
    ctx->r4 = ADD32(ctx->r4, 0X5660);
    // 0x801050CC: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x801050D0: addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    // 0x801050D4: addiu       $a3, $zero, 0x8
    ctx->r7 = ADD32(0, 0X8);
    // 0x801050D8: jal         0x800C7830
    // 0x801050DC: sw          $s1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r17;
    addBooleanCountHandleWrapper(rdram, ctx);
        goto after_10;
    // 0x801050DC: sw          $s1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r17;
    after_10:
    // 0x801050E0: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x801050E4: addiu       $a0, $a0, 0x5634
    ctx->r4 = ADD32(ctx->r4, 0X5634);
    // 0x801050E8: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x801050EC: addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    // 0x801050F0: addiu       $a3, $zero, 0x7
    ctx->r7 = ADD32(0, 0X7);
    // 0x801050F4: addiu       $s0, $zero, 0x3
    ctx->r16 = ADD32(0, 0X3);
    // 0x801050F8: jal         0x800C7830
    // 0x801050FC: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    addBooleanCountHandleWrapper(rdram, ctx);
        goto after_11;
    // 0x801050FC: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    after_11:
    // 0x80105100: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x80105104: addiu       $a0, $a0, 0x568C
    ctx->r4 = ADD32(ctx->r4, 0X568C);
    // 0x80105108: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x8010510C: addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    // 0x80105110: addiu       $a3, $zero, 0x7
    ctx->r7 = ADD32(0, 0X7);
    // 0x80105114: jal         0x800C7830
    // 0x80105118: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    addBooleanCountHandleWrapper(rdram, ctx);
        goto after_12;
    // 0x80105118: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    after_12:
    // 0x8010511C: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x80105120: addiu       $a0, $a0, 0x5790
    ctx->r4 = ADD32(ctx->r4, 0X5790);
    // 0x80105124: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80105128: addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    // 0x8010512C: addiu       $a3, $zero, 0x20
    ctx->r7 = ADD32(0, 0X20);
    // 0x80105130: jal         0x800C7830
    // 0x80105134: sw          $s1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r17;
    addBooleanCountHandleWrapper(rdram, ctx);
        goto after_13;
    // 0x80105134: sw          $s1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r17;
    after_13:
    // 0x80105138: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x8010513C: addiu       $a0, $a0, 0x58A0
    ctx->r4 = ADD32(ctx->r4, 0X58A0);
    // 0x80105140: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80105144: addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    // 0x80105148: addiu       $a3, $zero, 0xB
    ctx->r7 = ADD32(0, 0XB);
    // 0x8010514C: jal         0x800C7830
    // 0x80105150: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    addBooleanCountHandleWrapper(rdram, ctx);
        goto after_14;
    // 0x80105150: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    after_14:
    // 0x80105154: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x80105158: addiu       $a0, $a0, 0x59B0
    ctx->r4 = ADD32(ctx->r4, 0X59B0);
    // 0x8010515C: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80105160: addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    // 0x80105164: addiu       $a3, $zero, 0xE
    ctx->r7 = ADD32(0, 0XE);
    // 0x80105168: jal         0x800C7830
    // 0x8010516C: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    addBooleanCountHandleWrapper(rdram, ctx);
        goto after_15;
    // 0x8010516C: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    after_15:
    // 0x80105170: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x80105174: addiu       $a0, $a0, 0x5AC0
    ctx->r4 = ADD32(ctx->r4, 0X5AC0);
    // 0x80105178: addiu       $a1, $zero, 0x23
    ctx->r5 = ADD32(0, 0X23);
    // 0x8010517C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80105180: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // 0x80105184: jal         0x800C7830
    // 0x80105188: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    addBooleanCountHandleWrapper(rdram, ctx);
        goto after_16;
    // 0x80105188: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_16:
    // 0x8010518C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80105190: jal         0x800C7660
    // 0x80105194: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    setObjectiveHiddenFlag(rdram, ctx);
        goto after_17;
    // 0x80105194: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_17:
    // 0x80105198: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x8010519C: addiu       $a0, $a0, 0x5AE0
    ctx->r4 = ADD32(ctx->r4, 0X5AE0);
    // 0x801051A0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x801051A4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x801051A8: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // 0x801051AC: jal         0x800C7830
    // 0x801051B0: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    addBooleanCountHandleWrapper(rdram, ctx);
        goto after_18;
    // 0x801051B0: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_18:
    // 0x801051B4: lw          $ra, 0x20($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X20);
    // 0x801051B8: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x801051BC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x801051C0: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x801051C4: jr          $ra
    // 0x801051C8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x801051C8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void lv9_checkComplexObjectives(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801051CC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801051D0: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x801051D4: lui         $s0, 0x8011
    ctx->r16 = S32(0X8011 << 16);
    // 0x801051D8: lw          $v0, -0x2F30($s0)
    ctx->r2 = MEM_W(ctx->r16, -0X2F30);
    // 0x801051DC: bne         $v0, $zero, L_80105208
    if (ctx->r2 != 0) {
        // 0x801051E0: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_80105208;
    }
    // 0x801051E0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801051E4: jal         0x800C761C
    // 0x801051E8: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    getObjectiveCount(rdram, ctx);
        goto after_0;
    // 0x801051E8: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    after_0:
    // 0x801051EC: blez        $v0, L_80105208
    if (SIGNED(ctx->r2) <= 0) {
        // 0x801051F0: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80105208;
    }
    // 0x801051F0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x801051F4: jal         0x800C7738
    // 0x801051F8: sw          $v0, -0x2F30($s0)
    MEM_W(-0X2F30, ctx->r16) = ctx->r2;
    setHudEnableBit4(rdram, ctx);
        goto after_1;
    // 0x801051F8: sw          $v0, -0x2F30($s0)
    MEM_W(-0X2F30, ctx->r16) = ctx->r2;
    after_1:
    // 0x801051FC: addiu       $a0, $zero, 0x164
    ctx->r4 = ADD32(0, 0X164);
    // 0x80105200: jal         0x800C7D1C
    // 0x80105204: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    playObjectiveVoiceLine2(rdram, ctx);
        goto after_2;
    // 0x80105204: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_2:
L_80105208:
    // 0x80105208: jal         0x800C759C
    // 0x8010520C: addiu       $a0, $zero, 0xD
    ctx->r4 = ADD32(0, 0XD);
    getObjectiveBoolean(rdram, ctx);
        goto after_3;
    // 0x8010520C: addiu       $a0, $zero, 0xD
    ctx->r4 = ADD32(0, 0XD);
    after_3:
    // 0x80105210: blezl       $v0, L_8010522C
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80105214: lui         $a0, 0x800B
        ctx->r4 = S32(0X800B << 16);
            goto L_8010522C;
    }
    goto skip_0;
    // 0x80105214: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    skip_0:
    // 0x80105218: jal         0x800C776C
    // 0x8010521C: nop

    setHudEnableBit8(rdram, ctx);
        goto after_4;
    // 0x8010521C: nop

    after_4:
    // 0x80105220: jal         0x800C76B0
    // 0x80105224: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    activateObjectiveCompleteFlag(rdram, ctx);
        goto after_5;
    // 0x80105224: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_5:
    // 0x80105228: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
L_8010522C:
    // 0x8010522C: jal         0x800C7C28
    // 0x80105230: addiu       $a0, $a0, -0x67CC
    ctx->r4 = ADD32(ctx->r4, -0X67CC);
    getDatItemHealthPercentage(rdram, ctx);
        goto after_6;
    // 0x80105230: addiu       $a0, $a0, -0x67CC
    ctx->r4 = ADD32(ctx->r4, -0X67CC);
    after_6:
    // 0x80105234: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80105238: lwc1        $f2, -0x67BC($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X67BC);
    // 0x8010523C: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x80105240: nop

    // 0x80105244: bc1f        L_8010526C
    if (!c1cs) {
        // 0x80105248: lui         $v1, 0x8011
        ctx->r3 = S32(0X8011 << 16);
            goto L_8010526C;
    }
    // 0x80105248: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x8010524C: lw          $v0, -0x2F2C($v1)
    ctx->r2 = MEM_W(ctx->r3, -0X2F2C);
    // 0x80105250: bnel        $v0, $zero, L_80105270
    if (ctx->r2 != 0) {
        // 0x80105254: lui         $a0, 0x800B
        ctx->r4 = S32(0X800B << 16);
            goto L_80105270;
    }
    goto skip_1;
    // 0x80105254: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    skip_1:
    // 0x80105258: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8010525C: sw          $v0, -0x2F2C($v1)
    MEM_W(-0X2F2C, ctx->r3) = ctx->r2;
    // 0x80105260: addiu       $a0, $zero, 0xB
    ctx->r4 = ADD32(0, 0XB);
    // 0x80105264: jal         0x800C7D1C
    // 0x80105268: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    playObjectiveVoiceLine2(rdram, ctx);
        goto after_7;
    // 0x80105268: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_7:
L_8010526C:
    // 0x8010526C: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
L_80105270:
    // 0x80105270: jal         0x800C7C28
    // 0x80105274: addiu       $a0, $a0, -0x67CC
    ctx->r4 = ADD32(ctx->r4, -0X67CC);
    getDatItemHealthPercentage(rdram, ctx);
        goto after_8;
    // 0x80105274: addiu       $a0, $a0, -0x67CC
    ctx->r4 = ADD32(ctx->r4, -0X67CC);
    after_8:
    // 0x80105278: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8010527C: lwc1        $f2, -0x67B8($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X67B8);
    // 0x80105280: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x80105284: nop

    // 0x80105288: bc1f        L_801052B0
    if (!c1cs) {
        // 0x8010528C: lui         $v1, 0x8011
        ctx->r3 = S32(0X8011 << 16);
            goto L_801052B0;
    }
    // 0x8010528C: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x80105290: lw          $v0, -0x2F28($v1)
    ctx->r2 = MEM_W(ctx->r3, -0X2F28);
    // 0x80105294: bnel        $v0, $zero, L_801052B4
    if (ctx->r2 != 0) {
        // 0x80105298: lui         $a0, 0x800B
        ctx->r4 = S32(0X800B << 16);
            goto L_801052B4;
    }
    goto skip_2;
    // 0x80105298: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    skip_2:
    // 0x8010529C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x801052A0: sw          $v0, -0x2F28($v1)
    MEM_W(-0X2F28, ctx->r3) = ctx->r2;
    // 0x801052A4: addiu       $a0, $zero, 0x1A
    ctx->r4 = ADD32(0, 0X1A);
    // 0x801052A8: jal         0x800C7D1C
    // 0x801052AC: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    playObjectiveVoiceLine2(rdram, ctx);
        goto after_9;
    // 0x801052AC: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_9:
L_801052B0:
    // 0x801052B0: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
L_801052B4:
    // 0x801052B4: jal         0x800C7C28
    // 0x801052B8: addiu       $a0, $a0, -0x67CC
    ctx->r4 = ADD32(ctx->r4, -0X67CC);
    getDatItemHealthPercentage(rdram, ctx);
        goto after_10;
    // 0x801052B8: addiu       $a0, $a0, -0x67CC
    ctx->r4 = ADD32(ctx->r4, -0X67CC);
    after_10:
    // 0x801052BC: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x801052C0: lwc1        $f2, -0x67B4($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X67B4);
    // 0x801052C4: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x801052C8: nop

    // 0x801052CC: bc1f        L_801052F0
    if (!c1cs) {
        // 0x801052D0: lui         $v1, 0x8011
        ctx->r3 = S32(0X8011 << 16);
            goto L_801052F0;
    }
    // 0x801052D0: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x801052D4: lw          $v0, -0x2F24($v1)
    ctx->r2 = MEM_W(ctx->r3, -0X2F24);
    // 0x801052D8: bne         $v0, $zero, L_801052F0
    if (ctx->r2 != 0) {
        // 0x801052DC: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_801052F0;
    }
    // 0x801052DC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x801052E0: sw          $v0, -0x2F24($v1)
    MEM_W(-0X2F24, ctx->r3) = ctx->r2;
    // 0x801052E4: addiu       $a0, $zero, 0x1C
    ctx->r4 = ADD32(0, 0X1C);
    // 0x801052E8: jal         0x800C7D1C
    // 0x801052EC: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    playObjectiveVoiceLine2(rdram, ctx);
        goto after_11;
    // 0x801052EC: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_11:
L_801052F0:
    // 0x801052F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801052F4: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x801052F8: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x801052FC: jr          $ra
    // 0x80105300: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80105300: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void lv9_setMissionBooleansMass(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80105304: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80105308: addiu       $a0, $zero, 0x10E
    ctx->r4 = ADD32(0, 0X10E);
    // 0x8010530C: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80105310: jal         0x800C7D1C
    // 0x80105314: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    playObjectiveVoiceLine2(rdram, ctx);
        goto after_0;
    // 0x80105314: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_0:
    // 0x80105318: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    // 0x8010531C: jal         0x800C7540
    // 0x80105320: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    setObjectiveBoolean(rdram, ctx);
        goto after_1;
    // 0x80105320: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x80105324: addiu       $a0, $zero, 0x18
    ctx->r4 = ADD32(0, 0X18);
    // 0x80105328: jal         0x800C7540
    // 0x8010532C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    setObjectiveBoolean(rdram, ctx);
        goto after_2;
    // 0x8010532C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
    // 0x80105330: addiu       $a0, $zero, 0x19
    ctx->r4 = ADD32(0, 0X19);
    // 0x80105334: jal         0x800C7540
    // 0x80105338: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    setObjectiveBoolean(rdram, ctx);
        goto after_3;
    // 0x80105338: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_3:
    // 0x8010533C: addiu       $a0, $zero, 0x1A
    ctx->r4 = ADD32(0, 0X1A);
    // 0x80105340: jal         0x800C7540
    // 0x80105344: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    setObjectiveBoolean(rdram, ctx);
        goto after_4;
    // 0x80105344: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_4:
    // 0x80105348: addiu       $a0, $zero, 0x1B
    ctx->r4 = ADD32(0, 0X1B);
    // 0x8010534C: jal         0x800C7540
    // 0x80105350: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    setObjectiveBoolean(rdram, ctx);
        goto after_5;
    // 0x80105350: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_5:
    // 0x80105354: addiu       $a0, $zero, 0x1C
    ctx->r4 = ADD32(0, 0X1C);
    // 0x80105358: jal         0x800C7540
    // 0x8010535C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    setObjectiveBoolean(rdram, ctx);
        goto after_6;
    // 0x8010535C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_6:
    // 0x80105360: addiu       $a0, $zero, 0x1D
    ctx->r4 = ADD32(0, 0X1D);
    // 0x80105364: jal         0x800C7540
    // 0x80105368: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    setObjectiveBoolean(rdram, ctx);
        goto after_7;
    // 0x80105368: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_7:
    // 0x8010536C: addiu       $a0, $zero, 0x1E
    ctx->r4 = ADD32(0, 0X1E);
    // 0x80105370: jal         0x800C7540
    // 0x80105374: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    setObjectiveBoolean(rdram, ctx);
        goto after_8;
    // 0x80105374: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_8:
    // 0x80105378: addiu       $a0, $zero, 0x1F
    ctx->r4 = ADD32(0, 0X1F);
    // 0x8010537C: jal         0x800C7540
    // 0x80105380: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    setObjectiveBoolean(rdram, ctx);
        goto after_9;
    // 0x80105380: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_9:
    // 0x80105384: addiu       $a0, $zero, 0x21
    ctx->r4 = ADD32(0, 0X21);
    // 0x80105388: jal         0x800C7540
    // 0x8010538C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    setObjectiveBoolean(rdram, ctx);
        goto after_10;
    // 0x8010538C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_10:
    // 0x80105390: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80105394: jr          $ra
    // 0x80105398: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80105398: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void lv9_runDialogueSequenceA(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010539C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801053A0: lui         $a1, 0x3FC0
    ctx->r5 = S32(0X3FC0 << 16);
    // 0x801053A4: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x801053A8: jal         0x800C7D1C
    // 0x801053AC: addiu       $a0, $zero, 0x26D
    ctx->r4 = ADD32(0, 0X26D);
    playObjectiveVoiceLine2(rdram, ctx);
        goto after_0;
    // 0x801053AC: addiu       $a0, $zero, 0x26D
    ctx->r4 = ADD32(0, 0X26D);
    after_0:
    // 0x801053B0: addiu       $a0, $zero, 0x12
    ctx->r4 = ADD32(0, 0X12);
    // 0x801053B4: jal         0x800C7D1C
    // 0x801053B8: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    playObjectiveVoiceLine2(rdram, ctx);
        goto after_1;
    // 0x801053B8: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_1:
    // 0x801053BC: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x801053C0: jr          $ra
    // 0x801053C4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x801053C4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void scheduleLv9MajorStateTransition_1s(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801053C8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801053CC: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x801053D0: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    // 0x801053D4: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x801053D8: jal         0x800C7864
    // 0x801053DC: addiu       $a0, $a0, 0x53EC
    ctx->r4 = ADD32(ctx->r4, 0X53EC);
    addTimerHandleWrapper(rdram, ctx);
        goto after_0;
    // 0x801053DC: addiu       $a0, $a0, 0x53EC
    ctx->r4 = ADD32(ctx->r4, 0X53EC);
    after_0:
    // 0x801053E0: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x801053E4: jr          $ra
    // 0x801053E8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x801053E8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void lv9_majorStateTransition(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801053EC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801053F0: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x801053F4: jal         0x800C759C
    // 0x801053F8: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    getObjectiveBoolean(rdram, ctx);
        goto after_0;
    // 0x801053F8: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_0:
    // 0x801053FC: bne         $v0, $zero, L_80105458
    if (ctx->r2 != 0) {
        // 0x80105400: nop
    
            goto L_80105458;
    }
    // 0x80105400: nop

    // 0x80105404: jal         0x800C759C
    // 0x80105408: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    getObjectiveBoolean(rdram, ctx);
        goto after_1;
    // 0x80105408: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    after_1:
    // 0x8010540C: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x80105410: bne         $v0, $v1, L_80105458
    if (ctx->r2 != ctx->r3) {
        // 0x80105414: nop
    
            goto L_80105458;
    }
    // 0x80105414: nop

    // 0x80105418: lui         $a1, 0x3F00
    ctx->r5 = S32(0X3F00 << 16);
    // 0x8010541C: jal         0x800C7D1C
    // 0x80105420: addiu       $a0, $zero, 0x13
    ctx->r4 = ADD32(0, 0X13);
    playObjectiveVoiceLine2(rdram, ctx);
        goto after_2;
    // 0x80105420: addiu       $a0, $zero, 0x13
    ctx->r4 = ADD32(0, 0X13);
    after_2:
    // 0x80105424: addiu       $a0, $zero, 0x252
    ctx->r4 = ADD32(0, 0X252);
    // 0x80105428: jal         0x800C7D1C
    // 0x8010542C: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    playObjectiveVoiceLine2(rdram, ctx);
        goto after_3;
    // 0x8010542C: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_3:
    // 0x80105430: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x80105434: lui         $a1, 0x40A0
    ctx->r5 = S32(0X40A0 << 16);
    // 0x80105438: jal         0x800C7864
    // 0x8010543C: addiu       $a0, $a0, 0x5464
    ctx->r4 = ADD32(ctx->r4, 0X5464);
    addTimerHandleWrapper(rdram, ctx);
        goto after_4;
    // 0x8010543C: addiu       $a0, $a0, 0x5464
    ctx->r4 = ADD32(ctx->r4, 0X5464);
    after_4:
    // 0x80105440: addiu       $a0, $zero, 0x21
    ctx->r4 = ADD32(0, 0X21);
    // 0x80105444: jal         0x800C7540
    // 0x80105448: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    setObjectiveBoolean(rdram, ctx);
        goto after_5;
    // 0x80105448: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_5:
    // 0x8010544C: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x80105450: jal         0x800C7660
    // 0x80105454: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    setObjectiveHiddenFlag(rdram, ctx);
        goto after_6;
    // 0x80105454: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_6:
L_80105458:
    // 0x80105458: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x8010545C: jr          $ra
    // 0x80105460: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80105460: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void lv9_updateHudAndStateBools(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80105464: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80105468: addiu       $a0, $zero, 0x20
    ctx->r4 = ADD32(0, 0X20);
    // 0x8010546C: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80105470: jal         0x800C7540
    // 0x80105474: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    setObjectiveBoolean(rdram, ctx);
        goto after_0;
    // 0x80105474: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x80105478: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x8010547C: jal         0x800C7884
    // 0x80105480: addiu       $a0, $a0, -0x67B0
    ctx->r4 = ADD32(ctx->r4, -0X67B0);
    setHudFlagBit40AndStoreArg(rdram, ctx);
        goto after_1;
    // 0x80105480: addiu       $a0, $a0, -0x67B0
    ctx->r4 = ADD32(ctx->r4, -0X67B0);
    after_1:
    // 0x80105484: addiu       $a0, $zero, 0xE
    ctx->r4 = ADD32(0, 0XE);
    // 0x80105488: jal         0x800C7540
    // 0x8010548C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    setObjectiveBoolean(rdram, ctx);
        goto after_2;
    // 0x8010548C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
    // 0x80105490: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80105494: jr          $ra
    // 0x80105498: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80105498: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void scheduleLv9CompleteAndProgress_4s(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010549C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801054A0: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x801054A4: lui         $a1, 0x4080
    ctx->r5 = S32(0X4080 << 16);
    // 0x801054A8: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x801054AC: jal         0x800C7864
    // 0x801054B0: addiu       $a0, $a0, 0x54C0
    ctx->r4 = ADD32(ctx->r4, 0X54C0);
    addTimerHandleWrapper(rdram, ctx);
        goto after_0;
    // 0x801054B0: addiu       $a0, $a0, 0x54C0
    ctx->r4 = ADD32(ctx->r4, 0X54C0);
    after_0:
    // 0x801054B4: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x801054B8: jr          $ra
    // 0x801054BC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x801054BC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void lv9_completeAndProgressObjective(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801054C0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801054C4: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x801054C8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801054CC: jal         0x800C759C
    // 0x801054D0: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    getObjectiveBoolean(rdram, ctx);
        goto after_0;
    // 0x801054D0: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    after_0:
    // 0x801054D4: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // 0x801054D8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x801054DC: bne         $s0, $v0, L_8010551C
    if (ctx->r16 != ctx->r2) {
        // 0x801054E0: nop
    
            goto L_8010551C;
    }
    // 0x801054E0: nop

    // 0x801054E4: jal         0x800C759C
    // 0x801054E8: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    getObjectiveBoolean(rdram, ctx);
        goto after_1;
    // 0x801054E8: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    after_1:
    // 0x801054EC: bne         $v0, $s0, L_8010551C
    if (ctx->r2 != ctx->r16) {
        // 0x801054F0: addiu       $a0, $zero, 0x14
        ctx->r4 = ADD32(0, 0X14);
            goto L_8010551C;
    }
    // 0x801054F0: addiu       $a0, $zero, 0x14
    ctx->r4 = ADD32(0, 0X14);
    // 0x801054F4: jal         0x800C7D1C
    // 0x801054F8: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    playObjectiveVoiceLine2(rdram, ctx);
        goto after_2;
    // 0x801054F8: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_2:
    // 0x801054FC: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    // 0x80105500: jal         0x800C75EC
    // 0x80105504: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    increaseObjectiveCount(rdram, ctx);
        goto after_3;
    // 0x80105504: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_3:
    // 0x80105508: jal         0x800C76B0
    // 0x8010550C: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    activateObjectiveCompleteFlag(rdram, ctx);
        goto after_4;
    // 0x8010550C: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_4:
    // 0x80105510: addiu       $a0, $zero, 0x21
    ctx->r4 = ADD32(0, 0X21);
    // 0x80105514: jal         0x800C7540
    // 0x80105518: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    setObjectiveBoolean(rdram, ctx);
        goto after_5;
    // 0x80105518: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_5:
L_8010551C:
    // 0x8010551C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80105520: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80105524: jr          $ra
    // 0x80105528: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80105528: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void lv9_dialogueAndStateA(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010552C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80105530: addiu       $a0, $zero, 0x16
    ctx->r4 = ADD32(0, 0X16);
    // 0x80105534: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80105538: jal         0x800C7D1C
    // 0x8010553C: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    playObjectiveVoiceLine2(rdram, ctx);
        goto after_0;
    // 0x8010553C: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_0:
    // 0x80105540: lui         $a1, 0x4000
    ctx->r5 = S32(0X4000 << 16);
    // 0x80105544: jal         0x800C7D1C
    // 0x80105548: addiu       $a0, $zero, 0x2EB
    ctx->r4 = ADD32(0, 0X2EB);
    playObjectiveVoiceLine2(rdram, ctx);
        goto after_1;
    // 0x80105548: addiu       $a0, $zero, 0x2EB
    ctx->r4 = ADD32(0, 0X2EB);
    after_1:
    // 0x8010554C: addiu       $a0, $zero, 0x79
    ctx->r4 = ADD32(0, 0X79);
    // 0x80105550: jal         0x800C7540
    // 0x80105554: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    setObjectiveBoolean(rdram, ctx);
        goto after_2;
    // 0x80105554: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
    // 0x80105558: jal         0x800C7D98
    // 0x8010555C: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    triggerSoundCueByType(rdram, ctx);
        goto after_3;
    // 0x8010555C: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    after_3:
    // 0x80105560: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80105564: jr          $ra
    // 0x80105568: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80105568: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void lv9_dialogueAndStateB(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010556C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80105570: addiu       $a0, $zero, 0x16
    ctx->r4 = ADD32(0, 0X16);
    // 0x80105574: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80105578: jal         0x800C7D1C
    // 0x8010557C: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    playObjectiveVoiceLine2(rdram, ctx);
        goto after_0;
    // 0x8010557C: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_0:
    // 0x80105580: lui         $a1, 0x4000
    ctx->r5 = S32(0X4000 << 16);
    // 0x80105584: jal         0x800C7D1C
    // 0x80105588: addiu       $a0, $zero, 0x2EB
    ctx->r4 = ADD32(0, 0X2EB);
    playObjectiveVoiceLine2(rdram, ctx);
        goto after_1;
    // 0x80105588: addiu       $a0, $zero, 0x2EB
    ctx->r4 = ADD32(0, 0X2EB);
    after_1:
    // 0x8010558C: addiu       $a0, $zero, 0x7A
    ctx->r4 = ADD32(0, 0X7A);
    // 0x80105590: jal         0x800C7540
    // 0x80105594: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    setObjectiveBoolean(rdram, ctx);
        goto after_2;
    // 0x80105594: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
    // 0x80105598: jal         0x800C7D98
    // 0x8010559C: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    triggerSoundCueByType(rdram, ctx);
        goto after_3;
    // 0x8010559C: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    after_3:
    // 0x801055A0: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x801055A4: jr          $ra
    // 0x801055A8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x801055A8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void lv9_dialogueWithStateA(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801055AC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801055B0: addiu       $a0, $zero, 0x16
    ctx->r4 = ADD32(0, 0X16);
    // 0x801055B4: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x801055B8: jal         0x800C7D1C
    // 0x801055BC: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    playObjectiveVoiceLine2(rdram, ctx);
        goto after_0;
    // 0x801055BC: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_0:
    // 0x801055C0: addiu       $a0, $zero, 0x7B
    ctx->r4 = ADD32(0, 0X7B);
    // 0x801055C4: jal         0x800C7540
    // 0x801055C8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    setObjectiveBoolean(rdram, ctx);
        goto after_1;
    // 0x801055C8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x801055CC: jal         0x800C7D98
    // 0x801055D0: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    triggerSoundCueByType(rdram, ctx);
        goto after_2;
    // 0x801055D0: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    after_2:
    // 0x801055D4: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x801055D8: jr          $ra
    // 0x801055DC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x801055DC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void playVoice2_0x017(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801055E0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801055E4: addiu       $a0, $zero, 0x17
    ctx->r4 = ADD32(0, 0X17);
    // 0x801055E8: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x801055EC: jal         0x800C7D1C
    // 0x801055F0: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    playObjectiveVoiceLine2(rdram, ctx);
        goto after_0;
    // 0x801055F0: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_0:
    // 0x801055F4: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x801055F8: jr          $ra
    // 0x801055FC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x801055FC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void lv9_dialogueWithStateB(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80105600: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80105604: addiu       $a0, $zero, 0x18
    ctx->r4 = ADD32(0, 0X18);
    // 0x80105608: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x8010560C: jal         0x800C7D1C
    // 0x80105610: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    playObjectiveVoiceLine2(rdram, ctx);
        goto after_0;
    // 0x80105610: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_0:
    // 0x80105614: addiu       $a0, $zero, 0x7C
    ctx->r4 = ADD32(0, 0X7C);
    // 0x80105618: jal         0x800C7540
    // 0x8010561C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    setObjectiveBoolean(rdram, ctx);
        goto after_1;
    // 0x8010561C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x80105620: jal         0x800C7D98
    // 0x80105624: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    triggerSoundCueByType(rdram, ctx);
        goto after_2;
    // 0x80105624: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    after_2:
    // 0x80105628: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x8010562C: jr          $ra
    // 0x80105630: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80105630: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void lv9_playVoice7IfFlagClear(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80105634: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80105638: lw          $v0, -0x2F30($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X2F30);
    // 0x8010563C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80105640: bne         $v0, $zero, L_80105654
    if (ctx->r2 != 0) {
        // 0x80105644: sw          $ra, 0x10($sp)
        MEM_W(0X10, ctx->r29) = ctx->r31;
            goto L_80105654;
    }
    // 0x80105644: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80105648: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // 0x8010564C: jal         0x800C7D1C
    // 0x80105650: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    playObjectiveVoiceLine2(rdram, ctx);
        goto after_0;
    // 0x80105650: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_0:
L_80105654:
    // 0x80105654: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80105658: jr          $ra
    // 0x8010565C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8010565C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void lv9_playPairedDialogue(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80105660: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80105664: addiu       $a0, $zero, 0xB
    ctx->r4 = ADD32(0, 0XB);
    // 0x80105668: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x8010566C: jal         0x800C7D1C
    // 0x80105670: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    playObjectiveVoiceLine2(rdram, ctx);
        goto after_0;
    // 0x80105670: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_0:
    // 0x80105674: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    // 0x80105678: jal         0x800C7D1C
    // 0x8010567C: addiu       $a0, $zero, 0x1B
    ctx->r4 = ADD32(0, 0X1B);
    playObjectiveVoiceLine2(rdram, ctx);
        goto after_1;
    // 0x8010567C: addiu       $a0, $zero, 0x1B
    ctx->r4 = ADD32(0, 0X1B);
    after_1:
    // 0x80105680: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80105684: jr          $ra
    // 0x80105688: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80105688: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void bootstrapLv9ProgressTimerHead(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010568C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80105690: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x80105694: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    // 0x80105698: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x8010569C: jal         0x800C7864
    // 0x801056A0: addiu       $a0, $a0, 0x56B0
    ctx->r4 = ADD32(ctx->r4, 0X56B0);
    addTimerHandleWrapper(rdram, ctx);
        goto after_0;
    // 0x801056A0: addiu       $a0, $a0, 0x56B0
    ctx->r4 = ADD32(ctx->r4, 0X56B0);
    after_0:
    // 0x801056A4: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x801056A8: jr          $ra
    // 0x801056AC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x801056AC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void lv9_progressAndRescheduleTimer(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801056B0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801056B4: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    // 0x801056B8: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x801056BC: jal         0x800C75EC
    // 0x801056C0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    increaseObjectiveCount(rdram, ctx);
        goto after_0;
    // 0x801056C0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x801056C4: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x801056C8: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    // 0x801056CC: jal         0x800C7864
    // 0x801056D0: addiu       $a0, $a0, 0x56E0
    ctx->r4 = ADD32(ctx->r4, 0X56E0);
    addTimerHandleWrapper(rdram, ctx);
        goto after_1;
    // 0x801056D0: addiu       $a0, $a0, 0x56E0
    ctx->r4 = ADD32(ctx->r4, 0X56E0);
    after_1:
    // 0x801056D4: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x801056D8: jr          $ra
    // 0x801056DC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x801056DC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void lv9_progressObjective_0x13(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801056E0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801056E4: addiu       $a0, $zero, 0x13
    ctx->r4 = ADD32(0, 0X13);
    // 0x801056E8: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x801056EC: jal         0x800C75EC
    // 0x801056F0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    increaseObjectiveCount(rdram, ctx);
        goto after_0;
    // 0x801056F0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x801056F4: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x801056F8: lui         $a1, 0x4150
    ctx->r5 = S32(0X4150 << 16);
    // 0x801056FC: jal         0x800C7864
    // 0x80105700: addiu       $a0, $a0, 0x5710
    ctx->r4 = ADD32(ctx->r4, 0X5710);
    addTimerHandleWrapper(rdram, ctx);
        goto after_1;
    // 0x80105700: addiu       $a0, $a0, 0x5710
    ctx->r4 = ADD32(ctx->r4, 0X5710);
    after_1:
    // 0x80105704: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80105708: jr          $ra
    // 0x8010570C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8010570C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void lv9_progressObjective_0x11(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80105710: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80105714: addiu       $a0, $zero, 0x11
    ctx->r4 = ADD32(0, 0X11);
    // 0x80105718: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x8010571C: jal         0x800C75EC
    // 0x80105720: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    increaseObjectiveCount(rdram, ctx);
        goto after_0;
    // 0x80105720: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x80105724: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x80105728: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    // 0x8010572C: jal         0x800C7864
    // 0x80105730: addiu       $a0, $a0, 0x5740
    ctx->r4 = ADD32(ctx->r4, 0X5740);
    addTimerHandleWrapper(rdram, ctx);
        goto after_1;
    // 0x80105730: addiu       $a0, $a0, 0x5740
    ctx->r4 = ADD32(ctx->r4, 0X5740);
    after_1:
    // 0x80105734: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80105738: jr          $ra
    // 0x8010573C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8010573C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void lv9_progressObjective_0x12(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80105740: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80105744: addiu       $a0, $zero, 0x12
    ctx->r4 = ADD32(0, 0X12);
    // 0x80105748: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x8010574C: jal         0x800C75EC
    // 0x80105750: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    increaseObjectiveCount(rdram, ctx);
        goto after_0;
    // 0x80105750: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x80105754: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x80105758: lui         $a1, 0x4170
    ctx->r5 = S32(0X4170 << 16);
    // 0x8010575C: jal         0x800C7864
    // 0x80105760: addiu       $a0, $a0, 0x5770
    ctx->r4 = ADD32(ctx->r4, 0X5770);
    addTimerHandleWrapper(rdram, ctx);
        goto after_1;
    // 0x80105760: addiu       $a0, $a0, 0x5770
    ctx->r4 = ADD32(ctx->r4, 0X5770);
    after_1:
    // 0x80105764: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80105768: jr          $ra
    // 0x8010576C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8010576C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void setObjBoolTrue_0x14(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80105770: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80105774: addiu       $a0, $zero, 0x14
    ctx->r4 = ADD32(0, 0X14);
    // 0x80105778: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x8010577C: jal         0x800C7540
    // 0x80105780: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    setObjectiveBoolean(rdram, ctx);
        goto after_0;
    // 0x80105780: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x80105784: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80105788: jr          $ra
    // 0x8010578C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8010578C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void lv9_scheduleTimerAndDialogueA(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80105790: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80105794: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x80105798: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    // 0x8010579C: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x801057A0: jal         0x800C7864
    // 0x801057A4: addiu       $a0, $a0, 0x57C0
    ctx->r4 = ADD32(ctx->r4, 0X57C0);
    addTimerHandleWrapper(rdram, ctx);
        goto after_0;
    // 0x801057A4: addiu       $a0, $a0, 0x57C0
    ctx->r4 = ADD32(ctx->r4, 0X57C0);
    after_0:
    // 0x801057A8: addiu       $a0, $zero, 0x274
    ctx->r4 = ADD32(0, 0X274);
    // 0x801057AC: jal         0x800C7D1C
    // 0x801057B0: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    playObjectiveVoiceLine2(rdram, ctx);
        goto after_1;
    // 0x801057B0: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_1:
    // 0x801057B4: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x801057B8: jr          $ra
    // 0x801057BC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x801057BC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void lv9_progressObjective_0x14(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801057C0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801057C4: addiu       $a0, $zero, 0x14
    ctx->r4 = ADD32(0, 0X14);
    // 0x801057C8: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x801057CC: jal         0x800C75EC
    // 0x801057D0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    increaseObjectiveCount(rdram, ctx);
        goto after_0;
    // 0x801057D0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x801057D4: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x801057D8: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    // 0x801057DC: jal         0x800C7864
    // 0x801057E0: addiu       $a0, $a0, 0x57F0
    ctx->r4 = ADD32(ctx->r4, 0X57F0);
    addTimerHandleWrapper(rdram, ctx);
        goto after_1;
    // 0x801057E0: addiu       $a0, $a0, 0x57F0
    ctx->r4 = ADD32(ctx->r4, 0X57F0);
    after_1:
    // 0x801057E4: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x801057E8: jr          $ra
    // 0x801057EC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x801057EC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void lv9_progressObjective_0x17(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801057F0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801057F4: addiu       $a0, $zero, 0x17
    ctx->r4 = ADD32(0, 0X17);
    // 0x801057F8: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x801057FC: jal         0x800C75EC
    // 0x80105800: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    increaseObjectiveCount(rdram, ctx);
        goto after_0;
    // 0x80105800: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x80105804: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x80105808: lui         $a1, 0x4170
    ctx->r5 = S32(0X4170 << 16);
    // 0x8010580C: jal         0x800C7864
    // 0x80105810: addiu       $a0, $a0, 0x5820
    ctx->r4 = ADD32(ctx->r4, 0X5820);
    addTimerHandleWrapper(rdram, ctx);
        goto after_1;
    // 0x80105810: addiu       $a0, $a0, 0x5820
    ctx->r4 = ADD32(ctx->r4, 0X5820);
    after_1:
    // 0x80105814: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80105818: jr          $ra
    // 0x8010581C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8010581C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void lv9_progressObjective_0x15(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80105820: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80105824: addiu       $a0, $zero, 0x15
    ctx->r4 = ADD32(0, 0X15);
    // 0x80105828: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x8010582C: jal         0x800C75EC
    // 0x80105830: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    increaseObjectiveCount(rdram, ctx);
        goto after_0;
    // 0x80105830: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x80105834: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x80105838: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    // 0x8010583C: jal         0x800C7864
    // 0x80105840: addiu       $a0, $a0, 0x5850
    ctx->r4 = ADD32(ctx->r4, 0X5850);
    addTimerHandleWrapper(rdram, ctx);
        goto after_1;
    // 0x80105840: addiu       $a0, $a0, 0x5850
    ctx->r4 = ADD32(ctx->r4, 0X5850);
    after_1:
    // 0x80105844: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80105848: jr          $ra
    // 0x8010584C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8010584C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void lv9_progressObjective_0x16(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80105850: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80105854: addiu       $a0, $zero, 0x16
    ctx->r4 = ADD32(0, 0X16);
    // 0x80105858: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x8010585C: jal         0x800C75EC
    // 0x80105860: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    increaseObjectiveCount(rdram, ctx);
        goto after_0;
    // 0x80105860: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x80105864: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x80105868: lui         $a1, 0x41B0
    ctx->r5 = S32(0X41B0 << 16);
    // 0x8010586C: jal         0x800C7864
    // 0x80105870: addiu       $a0, $a0, 0x5880
    ctx->r4 = ADD32(ctx->r4, 0X5880);
    addTimerHandleWrapper(rdram, ctx);
        goto after_1;
    // 0x80105870: addiu       $a0, $a0, 0x5880
    ctx->r4 = ADD32(ctx->r4, 0X5880);
    after_1:
    // 0x80105874: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80105878: jr          $ra
    // 0x8010587C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8010587C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void setObjBoolTrue_0x15(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80105880: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80105884: addiu       $a0, $zero, 0x15
    ctx->r4 = ADD32(0, 0X15);
    // 0x80105888: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x8010588C: jal         0x800C7540
    // 0x80105890: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    setObjectiveBoolean(rdram, ctx);
        goto after_0;
    // 0x80105890: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x80105894: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80105898: jr          $ra
    // 0x8010589C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8010589C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void lv9_scheduleTimerAndDialogueB(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801058A0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801058A4: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x801058A8: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    // 0x801058AC: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x801058B0: jal         0x800C7864
    // 0x801058B4: addiu       $a0, $a0, 0x58D0
    ctx->r4 = ADD32(ctx->r4, 0X58D0);
    addTimerHandleWrapper(rdram, ctx);
        goto after_0;
    // 0x801058B4: addiu       $a0, $a0, 0x58D0
    ctx->r4 = ADD32(ctx->r4, 0X58D0);
    after_0:
    // 0x801058B8: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // 0x801058BC: jal         0x800C7D1C
    // 0x801058C0: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    playObjectiveVoiceLine2(rdram, ctx);
        goto after_1;
    // 0x801058C0: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_1:
    // 0x801058C4: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x801058C8: jr          $ra
    // 0x801058CC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x801058CC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void lv9_progressObjective_0x18(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801058D0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801058D4: addiu       $a0, $zero, 0x18
    ctx->r4 = ADD32(0, 0X18);
    // 0x801058D8: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x801058DC: jal         0x800C75EC
    // 0x801058E0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    increaseObjectiveCount(rdram, ctx);
        goto after_0;
    // 0x801058E0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x801058E4: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x801058E8: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    // 0x801058EC: jal         0x800C7864
    // 0x801058F0: addiu       $a0, $a0, 0x5900
    ctx->r4 = ADD32(ctx->r4, 0X5900);
    addTimerHandleWrapper(rdram, ctx);
        goto after_1;
    // 0x801058F0: addiu       $a0, $a0, 0x5900
    ctx->r4 = ADD32(ctx->r4, 0X5900);
    after_1:
    // 0x801058F4: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x801058F8: jr          $ra
    // 0x801058FC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x801058FC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void lv9_progressObjective_0x1B(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80105900: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80105904: addiu       $a0, $zero, 0x1B
    ctx->r4 = ADD32(0, 0X1B);
    // 0x80105908: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x8010590C: jal         0x800C75EC
    // 0x80105910: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    increaseObjectiveCount(rdram, ctx);
        goto after_0;
    // 0x80105910: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x80105914: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x80105918: lui         $a1, 0x4170
    ctx->r5 = S32(0X4170 << 16);
    // 0x8010591C: jal         0x800C7864
    // 0x80105920: addiu       $a0, $a0, 0x5930
    ctx->r4 = ADD32(ctx->r4, 0X5930);
    addTimerHandleWrapper(rdram, ctx);
        goto after_1;
    // 0x80105920: addiu       $a0, $a0, 0x5930
    ctx->r4 = ADD32(ctx->r4, 0X5930);
    after_1:
    // 0x80105924: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80105928: jr          $ra
    // 0x8010592C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8010592C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void lv9_progressObjective_0x19(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80105930: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80105934: addiu       $a0, $zero, 0x19
    ctx->r4 = ADD32(0, 0X19);
    // 0x80105938: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x8010593C: jal         0x800C75EC
    // 0x80105940: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    increaseObjectiveCount(rdram, ctx);
        goto after_0;
    // 0x80105940: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x80105944: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x80105948: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    // 0x8010594C: jal         0x800C7864
    // 0x80105950: addiu       $a0, $a0, 0x5960
    ctx->r4 = ADD32(ctx->r4, 0X5960);
    addTimerHandleWrapper(rdram, ctx);
        goto after_1;
    // 0x80105950: addiu       $a0, $a0, 0x5960
    ctx->r4 = ADD32(ctx->r4, 0X5960);
    after_1:
    // 0x80105954: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80105958: jr          $ra
    // 0x8010595C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8010595C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
