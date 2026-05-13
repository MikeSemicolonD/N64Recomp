#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void lv2_checkComplexObjectives(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80101EF4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80101EF8: sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // 0x80101EFC: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x80101F00: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80101F04: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x80101F08: jal         0x800C759C
    // 0x80101F0C: addiu       $a0, $zero, 0x65
    ctx->r4 = ADD32(0, 0X65);
    getObjectiveBoolean(rdram, ctx);
        goto after_0;
    // 0x80101F0C: addiu       $a0, $zero, 0x65
    ctx->r4 = ADD32(0, 0X65);
    after_0:
    // 0x80101F10: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x80101F14: bne         $v0, $v1, L_80101F44
    if (ctx->r2 != ctx->r3) {
        // 0x80101F18: nop
    
            goto L_80101F44;
    }
    // 0x80101F18: nop

    // 0x80101F1C: jal         0x800C76E0
    // 0x80101F20: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    getObjectiveTimer(rdram, ctx);
        goto after_1;
    // 0x80101F20: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    after_1:
    // 0x80101F24: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80101F28: lwc1        $f2, -0x6A10($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X6A10);
    // 0x80101F2C: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x80101F30: nop

    // 0x80101F34: bc1f        L_80101F44
    if (!c1cs) {
        // 0x80101F38: addiu       $a0, $zero, 0x65
        ctx->r4 = ADD32(0, 0X65);
            goto L_80101F44;
    }
    // 0x80101F38: addiu       $a0, $zero, 0x65
    ctx->r4 = ADD32(0, 0X65);
    // 0x80101F3C: jal         0x800C7540
    // 0x80101F40: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    setObjectiveBoolean(rdram, ctx);
        goto after_2;
    // 0x80101F40: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_2:
L_80101F44:
    // 0x80101F44: jal         0x800C759C
    // 0x80101F48: addiu       $a0, $zero, 0x65
    ctx->r4 = ADD32(0, 0X65);
    getObjectiveBoolean(rdram, ctx);
        goto after_3;
    // 0x80101F48: addiu       $a0, $zero, 0x65
    ctx->r4 = ADD32(0, 0X65);
    after_3:
    // 0x80101F4C: bne         $v0, $zero, L_8010212C
    if (ctx->r2 != 0) {
        // 0x80101F50: nop
    
            goto L_8010212C;
    }
    // 0x80101F50: nop

    // 0x80101F54: jal         0x800C759C
    // 0x80101F58: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    getObjectiveBoolean(rdram, ctx);
        goto after_4;
    // 0x80101F58: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_4:
    // 0x80101F5C: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // 0x80101F60: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80101F64: bne         $s0, $v0, L_80101FD4
    if (ctx->r16 != ctx->r2) {
        // 0x80101F68: nop
    
            goto L_80101FD4;
    }
    // 0x80101F68: nop

    // 0x80101F6C: jal         0x800C759C
    // 0x80101F70: addiu       $a0, $zero, 0x63
    ctx->r4 = ADD32(0, 0X63);
    getObjectiveBoolean(rdram, ctx);
        goto after_5;
    // 0x80101F70: addiu       $a0, $zero, 0x63
    ctx->r4 = ADD32(0, 0X63);
    after_5:
    // 0x80101F74: bne         $v0, $zero, L_80101FD4
    if (ctx->r2 != 0) {
        // 0x80101F78: nop
    
            goto L_80101FD4;
    }
    // 0x80101F78: nop

    // 0x80101F7C: jal         0x800C759C
    // 0x80101F80: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    getObjectiveBoolean(rdram, ctx);
        goto after_6;
    // 0x80101F80: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    after_6:
    // 0x80101F84: bne         $v0, $s0, L_80101FD4
    if (ctx->r2 != ctx->r16) {
        // 0x80101F88: nop
    
            goto L_80101FD4;
    }
    // 0x80101F88: nop

    // 0x80101F8C: jal         0x800C759C
    // 0x80101F90: addiu       $a0, $zero, 0x64
    ctx->r4 = ADD32(0, 0X64);
    getObjectiveBoolean(rdram, ctx);
        goto after_7;
    // 0x80101F90: addiu       $a0, $zero, 0x64
    ctx->r4 = ADD32(0, 0X64);
    after_7:
    // 0x80101F94: bne         $v0, $zero, L_80101FD4
    if (ctx->r2 != 0) {
        // 0x80101F98: addiu       $a0, $zero, 0x64
        ctx->r4 = ADD32(0, 0X64);
            goto L_80101FD4;
    }
    // 0x80101F98: addiu       $a0, $zero, 0x64
    ctx->r4 = ADD32(0, 0X64);
L_80101F9C:
    // 0x80101F9C: jal         0x800C7540
    // 0x80101FA0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    setObjectiveBoolean(rdram, ctx);
        goto after_8;
    // 0x80101FA0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_8:
    // 0x80101FA4: addiu       $a0, $zero, 0x65
    ctx->r4 = ADD32(0, 0X65);
    // 0x80101FA8: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x80101FAC: jal         0x800C7540
    // 0x80101FB0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    setObjectiveBoolean(rdram, ctx);
        goto after_9;
    // 0x80101FB0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_9:
    // 0x80101FB4: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80101FB8: jal         0x800C76FC
    // 0x80101FBC: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    setObjectiveTimer(rdram, ctx);
        goto after_10;
    // 0x80101FBC: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    after_10:
    // 0x80101FC0: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80101FC4: jal         0x800C7D1C
    // 0x80101FC8: addiu       $a0, $zero, 0x55
    ctx->r4 = ADD32(0, 0X55);
    playObjectiveVoiceLine2(rdram, ctx);
        goto after_11;
    // 0x80101FC8: addiu       $a0, $zero, 0x55
    ctx->r4 = ADD32(0, 0X55);
    after_11:
    // 0x80101FCC: j           L_801026B4
    // 0x80101FD0: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
        goto L_801026B4;
    // 0x80101FD0: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_80101FD4:
    // 0x80101FD4: jal         0x800C759C
    // 0x80101FD8: addiu       $a0, $zero, 0x64
    ctx->r4 = ADD32(0, 0X64);
    getObjectiveBoolean(rdram, ctx);
        goto after_12;
    // 0x80101FD8: addiu       $a0, $zero, 0x64
    ctx->r4 = ADD32(0, 0X64);
    after_12:
    // 0x80101FDC: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
    // 0x80101FE0: bne         $v0, $s1, L_80101FF0
    if (ctx->r2 != ctx->r17) {
        // 0x80101FE4: nop
    
            goto L_80101FF0;
    }
    // 0x80101FE4: nop

    // 0x80101FE8: jal         0x800C7738
    // 0x80101FEC: nop

    setHudEnableBit4(rdram, ctx);
        goto after_13;
    // 0x80101FEC: nop

    after_13:
L_80101FF0:
    // 0x80101FF0: jal         0x800C759C
    // 0x80101FF4: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    getObjectiveBoolean(rdram, ctx);
        goto after_14;
    // 0x80101FF4: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_14:
    // 0x80101FF8: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // 0x80101FFC: bne         $s0, $s1, L_80102034
    if (ctx->r16 != ctx->r17) {
        // 0x80102000: nop
    
            goto L_80102034;
    }
    // 0x80102000: nop

    // 0x80102004: jal         0x800C759C
    // 0x80102008: addiu       $a0, $zero, 0x63
    ctx->r4 = ADD32(0, 0X63);
    getObjectiveBoolean(rdram, ctx);
        goto after_15;
    // 0x80102008: addiu       $a0, $zero, 0x63
    ctx->r4 = ADD32(0, 0X63);
    after_15:
    // 0x8010200C: bne         $v0, $zero, L_80102034
    if (ctx->r2 != 0) {
        // 0x80102010: nop
    
            goto L_80102034;
    }
    // 0x80102010: nop

    // 0x80102014: jal         0x800C759C
    // 0x80102018: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    getObjectiveBoolean(rdram, ctx);
        goto after_16;
    // 0x80102018: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    after_16:
    // 0x8010201C: bne         $v0, $s0, L_80102034
    if (ctx->r2 != ctx->r16) {
        // 0x80102020: nop
    
            goto L_80102034;
    }
    // 0x80102020: nop

    // 0x80102024: jal         0x800C759C
    // 0x80102028: addiu       $a0, $zero, 0x64
    ctx->r4 = ADD32(0, 0X64);
    getObjectiveBoolean(rdram, ctx);
        goto after_17;
    // 0x80102028: addiu       $a0, $zero, 0x64
    ctx->r4 = ADD32(0, 0X64);
    after_17:
    // 0x8010202C: beq         $v0, $zero, L_80101F9C
    if (ctx->r2 == 0) {
        // 0x80102030: addiu       $a0, $zero, 0x64
        ctx->r4 = ADD32(0, 0X64);
            goto L_80101F9C;
    }
    // 0x80102030: addiu       $a0, $zero, 0x64
    ctx->r4 = ADD32(0, 0X64);
L_80102034:
    // 0x80102034: jal         0x800C759C
    // 0x80102038: addiu       $a0, $zero, 0x64
    ctx->r4 = ADD32(0, 0X64);
    getObjectiveBoolean(rdram, ctx);
        goto after_18;
    // 0x80102038: addiu       $a0, $zero, 0x64
    ctx->r4 = ADD32(0, 0X64);
    after_18:
    // 0x8010203C: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
    // 0x80102040: beq         $v0, $s1, L_80102094
    if (ctx->r2 == ctx->r17) {
        // 0x80102044: nop
    
            goto L_80102094;
    }
    // 0x80102044: nop

    // 0x80102048: jal         0x800C759C
    // 0x8010204C: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    getObjectiveBoolean(rdram, ctx);
        goto after_19;
    // 0x8010204C: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_19:
    // 0x80102050: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // 0x80102054: bne         $s0, $s1, L_8010209C
    if (ctx->r16 != ctx->r17) {
        // 0x80102058: nop
    
            goto L_8010209C;
    }
    // 0x80102058: nop

    // 0x8010205C: jal         0x800C759C
    // 0x80102060: addiu       $a0, $zero, 0x63
    ctx->r4 = ADD32(0, 0X63);
    getObjectiveBoolean(rdram, ctx);
        goto after_20;
    // 0x80102060: addiu       $a0, $zero, 0x63
    ctx->r4 = ADD32(0, 0X63);
    after_20:
    // 0x80102064: bne         $v0, $zero, L_8010209C
    if (ctx->r2 != 0) {
        // 0x80102068: nop
    
            goto L_8010209C;
    }
    // 0x80102068: nop

    // 0x8010206C: jal         0x800C759C
    // 0x80102070: addiu       $a0, $zero, 0x9
    ctx->r4 = ADD32(0, 0X9);
    getObjectiveBoolean(rdram, ctx);
        goto after_21;
    // 0x80102070: addiu       $a0, $zero, 0x9
    ctx->r4 = ADD32(0, 0X9);
    after_21:
    // 0x80102074: bne         $v0, $s0, L_8010209C
    if (ctx->r2 != ctx->r16) {
        // 0x80102078: nop
    
            goto L_8010209C;
    }
    // 0x80102078: nop

    // 0x8010207C: jal         0x800C759C
    // 0x80102080: addiu       $a0, $zero, 0x64
    ctx->r4 = ADD32(0, 0X64);
    getObjectiveBoolean(rdram, ctx);
        goto after_22;
    // 0x80102080: addiu       $a0, $zero, 0x64
    ctx->r4 = ADD32(0, 0X64);
    after_22:
    // 0x80102084: bne         $v0, $zero, L_8010209C
    if (ctx->r2 != 0) {
        // 0x80102088: addiu       $a0, $zero, 0x64
        ctx->r4 = ADD32(0, 0X64);
            goto L_8010209C;
    }
    // 0x80102088: addiu       $a0, $zero, 0x64
    ctx->r4 = ADD32(0, 0X64);
    // 0x8010208C: j           L_80101F9C
    // 0x80102090: nop

        goto L_80101F9C;
    // 0x80102090: nop

L_80102094:
    // 0x80102094: jal         0x800C7738
    // 0x80102098: nop

    setHudEnableBit4(rdram, ctx);
        goto after_23;
    // 0x80102098: nop

    after_23:
L_8010209C:
    // 0x8010209C: jal         0x800C759C
    // 0x801020A0: addiu       $a0, $zero, 0x64
    ctx->r4 = ADD32(0, 0X64);
    getObjectiveBoolean(rdram, ctx);
        goto after_24;
    // 0x801020A0: addiu       $a0, $zero, 0x64
    ctx->r4 = ADD32(0, 0X64);
    after_24:
    // 0x801020A4: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x801020A8: bne         $v0, $v1, L_801020B8
    if (ctx->r2 != ctx->r3) {
        // 0x801020AC: nop
    
            goto L_801020B8;
    }
    // 0x801020AC: nop

    // 0x801020B0: jal         0x800C7738
    // 0x801020B4: nop

    setHudEnableBit4(rdram, ctx);
        goto after_25;
    // 0x801020B4: nop

    after_25:
L_801020B8:
    // 0x801020B8: jal         0x800C761C
    // 0x801020BC: addiu       $a0, $zero, 0x28
    ctx->r4 = ADD32(0, 0X28);
    getObjectiveCount(rdram, ctx);
        goto after_26;
    // 0x801020BC: addiu       $a0, $zero, 0x28
    ctx->r4 = ADD32(0, 0X28);
    after_26:
    // 0x801020C0: blez        $v0, L_80102110
    if (SIGNED(ctx->r2) <= 0) {
        // 0x801020C4: nop
    
            goto L_80102110;
    }
    // 0x801020C4: nop

    // 0x801020C8: jal         0x800C759C
    // 0x801020CC: addiu       $a0, $zero, 0x6D
    ctx->r4 = ADD32(0, 0X6D);
    getObjectiveBoolean(rdram, ctx);
        goto after_27;
    // 0x801020CC: addiu       $a0, $zero, 0x6D
    ctx->r4 = ADD32(0, 0X6D);
    after_27:
    // 0x801020D0: bne         $v0, $zero, L_80102110
    if (ctx->r2 != 0) {
        // 0x801020D4: addiu       $a0, $zero, 0x6D
        ctx->r4 = ADD32(0, 0X6D);
            goto L_80102110;
    }
    // 0x801020D4: addiu       $a0, $zero, 0x6D
    ctx->r4 = ADD32(0, 0X6D);
    // 0x801020D8: jal         0x800C7540
    // 0x801020DC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    setObjectiveBoolean(rdram, ctx);
        goto after_28;
    // 0x801020DC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_28:
    // 0x801020E0: addiu       $a0, $zero, 0x65
    ctx->r4 = ADD32(0, 0X65);
    // 0x801020E4: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x801020E8: jal         0x800C7540
    // 0x801020EC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    setObjectiveBoolean(rdram, ctx);
        goto after_29;
    // 0x801020EC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_29:
    // 0x801020F0: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x801020F4: jal         0x800C76FC
    // 0x801020F8: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    setObjectiveTimer(rdram, ctx);
        goto after_30;
    // 0x801020F8: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    after_30:
    // 0x801020FC: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80102100: jal         0x800C7D1C
    // 0x80102104: addiu       $a0, $zero, 0x56
    ctx->r4 = ADD32(0, 0X56);
    playObjectiveVoiceLine2(rdram, ctx);
        goto after_31;
    // 0x80102104: addiu       $a0, $zero, 0x56
    ctx->r4 = ADD32(0, 0X56);
    after_31:
    // 0x80102108: j           L_801026B4
    // 0x8010210C: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
        goto L_801026B4;
    // 0x8010210C: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_80102110:
    // 0x80102110: jal         0x800C759C
    // 0x80102114: addiu       $a0, $zero, 0x6D
    ctx->r4 = ADD32(0, 0X6D);
    getObjectiveBoolean(rdram, ctx);
        goto after_32;
    // 0x80102114: addiu       $a0, $zero, 0x6D
    ctx->r4 = ADD32(0, 0X6D);
    after_32:
    // 0x80102118: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x8010211C: bne         $v0, $v1, L_8010212C
    if (ctx->r2 != ctx->r3) {
        // 0x80102120: nop
    
            goto L_8010212C;
    }
    // 0x80102120: nop

    // 0x80102124: jal         0x800C7738
    // 0x80102128: nop

    setHudEnableBit4(rdram, ctx);
        goto after_33;
    // 0x80102128: nop

    after_33:
L_8010212C:
    // 0x8010212C: jal         0x800C759C
    // 0x80102130: addiu       $a0, $zero, 0x80
    ctx->r4 = ADD32(0, 0X80);
    getObjectiveBoolean(rdram, ctx);
        goto after_34;
    // 0x80102130: addiu       $a0, $zero, 0x80
    ctx->r4 = ADD32(0, 0X80);
    after_34:
    // 0x80102134: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x80102138: bne         $v0, $v1, L_80102174
    if (ctx->r2 != ctx->r3) {
        // 0x8010213C: nop
    
            goto L_80102174;
    }
    // 0x8010213C: nop

    // 0x80102140: jal         0x800C759C
    // 0x80102144: addiu       $a0, $zero, 0x7F
    ctx->r4 = ADD32(0, 0X7F);
    getObjectiveBoolean(rdram, ctx);
        goto after_35;
    // 0x80102144: addiu       $a0, $zero, 0x7F
    ctx->r4 = ADD32(0, 0X7F);
    after_35:
    // 0x80102148: bne         $v0, $zero, L_80102174
    if (ctx->r2 != 0) {
        // 0x8010214C: addiu       $a0, $zero, 0x7F
        ctx->r4 = ADD32(0, 0X7F);
            goto L_80102174;
    }
    // 0x8010214C: addiu       $a0, $zero, 0x7F
    ctx->r4 = ADD32(0, 0X7F);
    // 0x80102150: jal         0x800C7540
    // 0x80102154: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    setObjectiveBoolean(rdram, ctx);
        goto after_36;
    // 0x80102154: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_36:
    // 0x80102158: jal         0x800C77D0
    // 0x8010215C: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    func_800C77D0(rdram, ctx);
        goto after_37;
    // 0x8010215C: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_37:
    // 0x80102160: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x80102164: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80102168: addiu       $a0, $v0, 0x1
    ctx->r4 = ADD32(ctx->r2, 0X1);
    // 0x8010216C: jal         0x800C7540
    // 0x80102170: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    setObjectiveBoolean(rdram, ctx);
        goto after_38;
    // 0x80102170: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_38:
L_80102174:
    // 0x80102174: jal         0x800C759C
    // 0x80102178: addiu       $a0, $zero, 0x3B
    ctx->r4 = ADD32(0, 0X3B);
    getObjectiveBoolean(rdram, ctx);
        goto after_39;
    // 0x80102178: addiu       $a0, $zero, 0x3B
    ctx->r4 = ADD32(0, 0X3B);
    after_39:
    // 0x8010217C: bne         $v0, $zero, L_80102270
    if (ctx->r2 != 0) {
        // 0x80102180: nop
    
            goto L_80102270;
    }
    // 0x80102180: nop

    // 0x80102184: jal         0x800C76E0
    // 0x80102188: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    getObjectiveTimer(rdram, ctx);
        goto after_40;
    // 0x80102188: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_40:
    // 0x8010218C: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80102190: lwc1        $f2, -0x6A0C($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X6A0C);
    // 0x80102194: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x80102198: nop

    // 0x8010219C: bc1f        L_80102270
    if (!c1cs) {
        // 0x801021A0: nop
    
            goto L_80102270;
    }
    // 0x801021A0: nop

    // 0x801021A4: jal         0x800C759C
    // 0x801021A8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    getObjectiveBoolean(rdram, ctx);
        goto after_41;
    // 0x801021A8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_41:
    // 0x801021AC: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x801021B0: bne         $v0, $v1, L_801021E8
    if (ctx->r2 != ctx->r3) {
        // 0x801021B4: nop
    
            goto L_801021E8;
    }
    // 0x801021B4: nop

    // 0x801021B8: jal         0x800C759C
    // 0x801021BC: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    getObjectiveBoolean(rdram, ctx);
        goto after_42;
    // 0x801021BC: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    after_42:
    // 0x801021C0: bne         $v0, $zero, L_801021E8
    if (ctx->r2 != 0) {
        // 0x801021C4: addiu       $a0, $zero, 0x15
        ctx->r4 = ADD32(0, 0X15);
            goto L_801021E8;
    }
    // 0x801021C4: addiu       $a0, $zero, 0x15
    ctx->r4 = ADD32(0, 0X15);
    // 0x801021C8: jal         0x800C7540
    // 0x801021CC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    setObjectiveBoolean(rdram, ctx);
        goto after_43;
    // 0x801021CC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_43:
    // 0x801021D0: addiu       $a0, $zero, 0x3B
    ctx->r4 = ADD32(0, 0X3B);
    // 0x801021D4: jal         0x800C7540
    // 0x801021D8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    setObjectiveBoolean(rdram, ctx);
        goto after_44;
    // 0x801021D8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_44:
    // 0x801021DC: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x801021E0: jal         0x800C7660
    // 0x801021E4: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    setObjectiveHiddenFlag(rdram, ctx);
        goto after_45;
    // 0x801021E4: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_45:
L_801021E8:
    // 0x801021E8: jal         0x800C759C
    // 0x801021EC: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    getObjectiveBoolean(rdram, ctx);
        goto after_46;
    // 0x801021EC: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_46:
    // 0x801021F0: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x801021F4: bne         $v0, $v1, L_8010222C
    if (ctx->r2 != ctx->r3) {
        // 0x801021F8: nop
    
            goto L_8010222C;
    }
    // 0x801021F8: nop

    // 0x801021FC: jal         0x800C759C
    // 0x80102200: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    getObjectiveBoolean(rdram, ctx);
        goto after_47;
    // 0x80102200: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    after_47:
    // 0x80102204: bne         $v0, $zero, L_8010222C
    if (ctx->r2 != 0) {
        // 0x80102208: addiu       $a0, $zero, 0x16
        ctx->r4 = ADD32(0, 0X16);
            goto L_8010222C;
    }
    // 0x80102208: addiu       $a0, $zero, 0x16
    ctx->r4 = ADD32(0, 0X16);
    // 0x8010220C: jal         0x800C7540
    // 0x80102210: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    setObjectiveBoolean(rdram, ctx);
        goto after_48;
    // 0x80102210: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_48:
    // 0x80102214: addiu       $a0, $zero, 0x3B
    ctx->r4 = ADD32(0, 0X3B);
    // 0x80102218: jal         0x800C7540
    // 0x8010221C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    setObjectiveBoolean(rdram, ctx);
        goto after_49;
    // 0x8010221C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_49:
    // 0x80102220: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x80102224: jal         0x800C7660
    // 0x80102228: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    setObjectiveHiddenFlag(rdram, ctx);
        goto after_50;
    // 0x80102228: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_50:
L_8010222C:
    // 0x8010222C: jal         0x800C759C
    // 0x80102230: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    getObjectiveBoolean(rdram, ctx);
        goto after_51;
    // 0x80102230: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_51:
    // 0x80102234: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x80102238: bne         $v0, $v1, L_80102270
    if (ctx->r2 != ctx->r3) {
        // 0x8010223C: nop
    
            goto L_80102270;
    }
    // 0x8010223C: nop

    // 0x80102240: jal         0x800C759C
    // 0x80102244: addiu       $a0, $zero, 0x9
    ctx->r4 = ADD32(0, 0X9);
    getObjectiveBoolean(rdram, ctx);
        goto after_52;
    // 0x80102244: addiu       $a0, $zero, 0x9
    ctx->r4 = ADD32(0, 0X9);
    after_52:
    // 0x80102248: bne         $v0, $zero, L_80102270
    if (ctx->r2 != 0) {
        // 0x8010224C: addiu       $a0, $zero, 0x17
        ctx->r4 = ADD32(0, 0X17);
            goto L_80102270;
    }
    // 0x8010224C: addiu       $a0, $zero, 0x17
    ctx->r4 = ADD32(0, 0X17);
    // 0x80102250: jal         0x800C7540
    // 0x80102254: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    setObjectiveBoolean(rdram, ctx);
        goto after_53;
    // 0x80102254: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_53:
    // 0x80102258: addiu       $a0, $zero, 0x3B
    ctx->r4 = ADD32(0, 0X3B);
    // 0x8010225C: jal         0x800C7540
    // 0x80102260: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    setObjectiveBoolean(rdram, ctx);
        goto after_54;
    // 0x80102260: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_54:
    // 0x80102264: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x80102268: jal         0x800C7660
    // 0x8010226C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    setObjectiveHiddenFlag(rdram, ctx);
        goto after_55;
    // 0x8010226C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_55:
L_80102270:
    // 0x80102270: jal         0x800C759C
    // 0x80102274: addiu       $a0, $zero, 0x3C
    ctx->r4 = ADD32(0, 0X3C);
    getObjectiveBoolean(rdram, ctx);
        goto after_56;
    // 0x80102274: addiu       $a0, $zero, 0x3C
    ctx->r4 = ADD32(0, 0X3C);
    after_56:
    // 0x80102278: bne         $v0, $zero, L_80102310
    if (ctx->r2 != 0) {
        // 0x8010227C: nop
    
            goto L_80102310;
    }
    // 0x8010227C: nop

    // 0x80102280: jal         0x800C76E0
    // 0x80102284: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    getObjectiveTimer(rdram, ctx);
        goto after_57;
    // 0x80102284: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_57:
    // 0x80102288: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8010228C: lwc1        $f2, -0x6A08($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X6A08);
    // 0x80102290: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x80102294: nop

    // 0x80102298: bc1f        L_80102310
    if (!c1cs) {
        // 0x8010229C: nop
    
            goto L_80102310;
    }
    // 0x8010229C: nop

    // 0x801022A0: jal         0x800C759C
    // 0x801022A4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    getObjectiveBoolean(rdram, ctx);
        goto after_58;
    // 0x801022A4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_58:
    // 0x801022A8: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
    // 0x801022AC: bne         $v0, $s0, L_801022C8
    if (ctx->r2 != ctx->r16) {
        // 0x801022B0: addiu       $a0, $zero, 0xB
        ctx->r4 = ADD32(0, 0XB);
            goto L_801022C8;
    }
    // 0x801022B0: addiu       $a0, $zero, 0xB
    ctx->r4 = ADD32(0, 0XB);
    // 0x801022B4: jal         0x800C7540
    // 0x801022B8: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    setObjectiveBoolean(rdram, ctx);
        goto after_59;
    // 0x801022B8: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    after_59:
    // 0x801022BC: addiu       $a0, $zero, 0x3C
    ctx->r4 = ADD32(0, 0X3C);
    // 0x801022C0: jal         0x800C7540
    // 0x801022C4: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    setObjectiveBoolean(rdram, ctx);
        goto after_60;
    // 0x801022C4: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    after_60:
L_801022C8:
    // 0x801022C8: jal         0x800C759C
    // 0x801022CC: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    getObjectiveBoolean(rdram, ctx);
        goto after_61;
    // 0x801022CC: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_61:
    // 0x801022D0: bne         $v0, $s0, L_801022EC
    if (ctx->r2 != ctx->r16) {
        // 0x801022D4: addiu       $a0, $zero, 0xC
        ctx->r4 = ADD32(0, 0XC);
            goto L_801022EC;
    }
    // 0x801022D4: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
    // 0x801022D8: jal         0x800C7540
    // 0x801022DC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    setObjectiveBoolean(rdram, ctx);
        goto after_62;
    // 0x801022DC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_62:
    // 0x801022E0: addiu       $a0, $zero, 0x3C
    ctx->r4 = ADD32(0, 0X3C);
    // 0x801022E4: jal         0x800C7540
    // 0x801022E8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    setObjectiveBoolean(rdram, ctx);
        goto after_63;
    // 0x801022E8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_63:
L_801022EC:
    // 0x801022EC: jal         0x800C759C
    // 0x801022F0: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    getObjectiveBoolean(rdram, ctx);
        goto after_64;
    // 0x801022F0: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_64:
    // 0x801022F4: bne         $v0, $s0, L_80102310
    if (ctx->r2 != ctx->r16) {
        // 0x801022F8: addiu       $a0, $zero, 0xD
        ctx->r4 = ADD32(0, 0XD);
            goto L_80102310;
    }
    // 0x801022F8: addiu       $a0, $zero, 0xD
    ctx->r4 = ADD32(0, 0XD);
    // 0x801022FC: jal         0x800C7540
    // 0x80102300: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    setObjectiveBoolean(rdram, ctx);
        goto after_65;
    // 0x80102300: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_65:
    // 0x80102304: addiu       $a0, $zero, 0x3C
    ctx->r4 = ADD32(0, 0X3C);
    // 0x80102308: jal         0x800C7540
    // 0x8010230C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    setObjectiveBoolean(rdram, ctx);
        goto after_66;
    // 0x8010230C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_66:
L_80102310:
    // 0x80102310: jal         0x800C759C
    // 0x80102314: addiu       $a0, $zero, 0x63
    ctx->r4 = ADD32(0, 0X63);
    getObjectiveBoolean(rdram, ctx);
        goto after_67;
    // 0x80102314: addiu       $a0, $zero, 0x63
    ctx->r4 = ADD32(0, 0X63);
    after_67:
    // 0x80102318: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // 0x8010231C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80102320: bne         $s0, $v0, L_80102380
    if (ctx->r16 != ctx->r2) {
        // 0x80102324: nop
    
            goto L_80102380;
    }
    // 0x80102324: nop

    // 0x80102328: jal         0x800C759C
    // 0x8010232C: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    getObjectiveBoolean(rdram, ctx);
        goto after_68;
    // 0x8010232C: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    after_68:
    // 0x80102330: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x80102334: bne         $v1, $s0, L_80102380
    if (ctx->r3 != ctx->r16) {
        // 0x80102338: lui         $a0, 0x8011
        ctx->r4 = S32(0X8011 << 16);
            goto L_80102380;
    }
    // 0x80102338: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x8010233C: lw          $v0, -0x493C($a0)
    ctx->r2 = MEM_W(ctx->r4, -0X493C);
    // 0x80102340: bne         $v0, $zero, L_80102380
    if (ctx->r2 != 0) {
        // 0x80102344: nop
    
            goto L_80102380;
    }
    // 0x80102344: nop

    // 0x80102348: sw          $v1, -0x493C($a0)
    MEM_W(-0X493C, ctx->r4) = ctx->r3;
    // 0x8010234C: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x80102350: jal         0x800C7884
    // 0x80102354: addiu       $a0, $a0, -0x6A34
    ctx->r4 = ADD32(ctx->r4, -0X6A34);
    setHudFlagBit40AndStoreArg(rdram, ctx);
        goto after_69;
    // 0x80102354: addiu       $a0, $a0, -0x6A34
    ctx->r4 = ADD32(ctx->r4, -0X6A34);
    after_69:
    // 0x80102358: jal         0x800C76B0
    // 0x8010235C: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    activateObjectiveCompleteFlag(rdram, ctx);
        goto after_70;
    // 0x8010235C: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_70:
    // 0x80102360: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x80102364: addiu       $a0, $a0, -0x4940
    ctx->r4 = ADD32(ctx->r4, -0X4940);
    // 0x80102368: jal         0x800C7568
    // 0x8010236C: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    setObjectiveBooleans(rdram, ctx);
        goto after_71;
    // 0x8010236C: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_71:
    // 0x80102370: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x80102374: addiu       $a0, $a0, -0x6A4C
    ctx->r4 = ADD32(ctx->r4, -0X6A4C);
    // 0x80102378: jal         0x800C7D60
    // 0x8010237C: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    delegateToLevelStageTick(rdram, ctx);
        goto after_72;
    // 0x8010237C: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_72:
L_80102380:
    // 0x80102380: jal         0x800C759C
    // 0x80102384: addiu       $a0, $zero, 0x63
    ctx->r4 = ADD32(0, 0X63);
    getObjectiveBoolean(rdram, ctx);
        goto after_73;
    // 0x80102384: addiu       $a0, $zero, 0x63
    ctx->r4 = ADD32(0, 0X63);
    after_73:
    // 0x80102388: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // 0x8010238C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80102390: bne         $s0, $v0, L_801023F0
    if (ctx->r16 != ctx->r2) {
        // 0x80102394: nop
    
            goto L_801023F0;
    }
    // 0x80102394: nop

    // 0x80102398: jal         0x800C759C
    // 0x8010239C: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    getObjectiveBoolean(rdram, ctx);
        goto after_74;
    // 0x8010239C: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_74:
    // 0x801023A0: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x801023A4: bne         $v1, $s0, L_801023F0
    if (ctx->r3 != ctx->r16) {
        // 0x801023A8: lui         $a0, 0x8011
        ctx->r4 = S32(0X8011 << 16);
            goto L_801023F0;
    }
    // 0x801023A8: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x801023AC: lw          $v0, -0x4938($a0)
    ctx->r2 = MEM_W(ctx->r4, -0X4938);
    // 0x801023B0: bne         $v0, $zero, L_801023F0
    if (ctx->r2 != 0) {
        // 0x801023B4: nop
    
            goto L_801023F0;
    }
    // 0x801023B4: nop

    // 0x801023B8: sw          $v1, -0x4938($a0)
    MEM_W(-0X4938, ctx->r4) = ctx->r3;
    // 0x801023BC: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x801023C0: jal         0x800C7884
    // 0x801023C4: addiu       $a0, $a0, -0x6A28
    ctx->r4 = ADD32(ctx->r4, -0X6A28);
    setHudFlagBit40AndStoreArg(rdram, ctx);
        goto after_75;
    // 0x801023C4: addiu       $a0, $a0, -0x6A28
    ctx->r4 = ADD32(ctx->r4, -0X6A28);
    after_75:
    // 0x801023C8: jal         0x800C76B0
    // 0x801023CC: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    activateObjectiveCompleteFlag(rdram, ctx);
        goto after_76;
    // 0x801023CC: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_76:
    // 0x801023D0: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x801023D4: addiu       $a0, $a0, -0x4940
    ctx->r4 = ADD32(ctx->r4, -0X4940);
    // 0x801023D8: jal         0x800C7568
    // 0x801023DC: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    setObjectiveBooleans(rdram, ctx);
        goto after_77;
    // 0x801023DC: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_77:
    // 0x801023E0: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x801023E4: addiu       $a0, $a0, -0x6A4C
    ctx->r4 = ADD32(ctx->r4, -0X6A4C);
    // 0x801023E8: jal         0x800C7D60
    // 0x801023EC: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    delegateToLevelStageTick(rdram, ctx);
        goto after_78;
    // 0x801023EC: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_78:
L_801023F0:
    // 0x801023F0: jal         0x800C759C
    // 0x801023F4: addiu       $a0, $zero, 0x63
    ctx->r4 = ADD32(0, 0X63);
    getObjectiveBoolean(rdram, ctx);
        goto after_79;
    // 0x801023F4: addiu       $a0, $zero, 0x63
    ctx->r4 = ADD32(0, 0X63);
    after_79:
    // 0x801023F8: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // 0x801023FC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80102400: bne         $s0, $v0, L_80102460
    if (ctx->r16 != ctx->r2) {
        // 0x80102404: nop
    
            goto L_80102460;
    }
    // 0x80102404: nop

    // 0x80102408: jal         0x800C759C
    // 0x8010240C: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    getObjectiveBoolean(rdram, ctx);
        goto after_80;
    // 0x8010240C: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_80:
    // 0x80102410: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x80102414: bne         $v1, $s0, L_80102460
    if (ctx->r3 != ctx->r16) {
        // 0x80102418: lui         $a0, 0x8011
        ctx->r4 = S32(0X8011 << 16);
            goto L_80102460;
    }
    // 0x80102418: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x8010241C: lw          $v0, -0x4934($a0)
    ctx->r2 = MEM_W(ctx->r4, -0X4934);
    // 0x80102420: bne         $v0, $zero, L_80102460
    if (ctx->r2 != 0) {
        // 0x80102424: nop
    
            goto L_80102460;
    }
    // 0x80102424: nop

    // 0x80102428: sw          $v1, -0x4934($a0)
    MEM_W(-0X4934, ctx->r4) = ctx->r3;
    // 0x8010242C: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x80102430: jal         0x800C7884
    // 0x80102434: addiu       $a0, $a0, -0x6A1C
    ctx->r4 = ADD32(ctx->r4, -0X6A1C);
    setHudFlagBit40AndStoreArg(rdram, ctx);
        goto after_81;
    // 0x80102434: addiu       $a0, $a0, -0x6A1C
    ctx->r4 = ADD32(ctx->r4, -0X6A1C);
    after_81:
    // 0x80102438: jal         0x800C76B0
    // 0x8010243C: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    activateObjectiveCompleteFlag(rdram, ctx);
        goto after_82;
    // 0x8010243C: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_82:
    // 0x80102440: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x80102444: addiu       $a0, $a0, -0x4940
    ctx->r4 = ADD32(ctx->r4, -0X4940);
    // 0x80102448: jal         0x800C7568
    // 0x8010244C: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    setObjectiveBooleans(rdram, ctx);
        goto after_83;
    // 0x8010244C: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_83:
    // 0x80102450: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x80102454: addiu       $a0, $a0, -0x6A4C
    ctx->r4 = ADD32(ctx->r4, -0X6A4C);
    // 0x80102458: jal         0x800C7D60
    // 0x8010245C: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    delegateToLevelStageTick(rdram, ctx);
        goto after_84;
    // 0x8010245C: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_84:
L_80102460:
    // 0x80102460: jal         0x800C759C
    // 0x80102464: addiu       $a0, $zero, 0x1F
    ctx->r4 = ADD32(0, 0X1F);
    getObjectiveBoolean(rdram, ctx);
        goto after_85;
    // 0x80102464: addiu       $a0, $zero, 0x1F
    ctx->r4 = ADD32(0, 0X1F);
    after_85:
    // 0x80102468: bne         $v0, $zero, L_801024D4
    if (ctx->r2 != 0) {
        // 0x8010246C: nop
    
            goto L_801024D4;
    }
    // 0x8010246C: nop

    // 0x80102470: jal         0x800C759C
    // 0x80102474: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    getObjectiveBoolean(rdram, ctx);
        goto after_86;
    // 0x80102474: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_86:
    // 0x80102478: addu        $s1, $v0, $zero
    ctx->r17 = ADD32(ctx->r2, 0);
    // 0x8010247C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80102480: bne         $s1, $v0, L_801024D4
    if (ctx->r17 != ctx->r2) {
        // 0x80102484: nop
    
            goto L_801024D4;
    }
    // 0x80102484: nop

    // 0x80102488: jal         0x800C759C
    // 0x8010248C: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    getObjectiveBoolean(rdram, ctx);
        goto after_87;
    // 0x8010248C: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    after_87:
    // 0x80102490: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // 0x80102494: bne         $s0, $s1, L_801024D4
    if (ctx->r16 != ctx->r17) {
        // 0x80102498: nop
    
            goto L_801024D4;
    }
    // 0x80102498: nop

    // 0x8010249C: jal         0x800C759C
    // 0x801024A0: addiu       $a0, $zero, 0x63
    ctx->r4 = ADD32(0, 0X63);
    getObjectiveBoolean(rdram, ctx);
        goto after_88;
    // 0x801024A0: addiu       $a0, $zero, 0x63
    ctx->r4 = ADD32(0, 0X63);
    after_88:
    // 0x801024A4: bne         $v0, $s0, L_801024D4
    if (ctx->r2 != ctx->r16) {
        // 0x801024A8: nop
    
            goto L_801024D4;
    }
    // 0x801024A8: nop

    // 0x801024AC: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x801024B0: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x801024B4: jal         0x800C76FC
    // 0x801024B8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    setObjectiveTimer(rdram, ctx);
        goto after_89;
    // 0x801024B8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_89:
    // 0x801024BC: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x801024C0: jal         0x800C76FC
    // 0x801024C4: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    setObjectiveTimer(rdram, ctx);
        goto after_90;
    // 0x801024C4: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_90:
    // 0x801024C8: addiu       $a0, $zero, 0x1F
    ctx->r4 = ADD32(0, 0X1F);
    // 0x801024CC: jal         0x800C7540
    // 0x801024D0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    setObjectiveBoolean(rdram, ctx);
        goto after_91;
    // 0x801024D0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_91:
L_801024D4:
    // 0x801024D4: jal         0x800C759C
    // 0x801024D8: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    getObjectiveBoolean(rdram, ctx);
        goto after_92;
    // 0x801024D8: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    after_92:
    // 0x801024DC: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x801024E0: bne         $v0, $v1, L_80102508
    if (ctx->r2 != ctx->r3) {
        // 0x801024E4: nop
    
            goto L_80102508;
    }
    // 0x801024E4: nop

    // 0x801024E8: jal         0x800C759C
    // 0x801024EC: addiu       $a0, $zero, 0x66
    ctx->r4 = ADD32(0, 0X66);
    getObjectiveBoolean(rdram, ctx);
        goto after_93;
    // 0x801024EC: addiu       $a0, $zero, 0x66
    ctx->r4 = ADD32(0, 0X66);
    after_93:
    // 0x801024F0: bne         $v0, $zero, L_80102508
    if (ctx->r2 != 0) {
        // 0x801024F4: addiu       $a0, $zero, 0x66
        ctx->r4 = ADD32(0, 0X66);
            goto L_80102508;
    }
    // 0x801024F4: addiu       $a0, $zero, 0x66
    ctx->r4 = ADD32(0, 0X66);
    // 0x801024F8: jal         0x800C7540
    // 0x801024FC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    setObjectiveBoolean(rdram, ctx);
        goto after_94;
    // 0x801024FC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_94:
    // 0x80102500: jal         0x800C76B0
    // 0x80102504: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    activateObjectiveCompleteFlag(rdram, ctx);
        goto after_95;
    // 0x80102504: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_95:
L_80102508:
    // 0x80102508: jal         0x800C759C
    // 0x8010250C: addiu       $a0, $zero, 0x1F
    ctx->r4 = ADD32(0, 0X1F);
    getObjectiveBoolean(rdram, ctx);
        goto after_96;
    // 0x8010250C: addiu       $a0, $zero, 0x1F
    ctx->r4 = ADD32(0, 0X1F);
    after_96:
    // 0x80102510: bne         $v0, $zero, L_8010257C
    if (ctx->r2 != 0) {
        // 0x80102514: nop
    
            goto L_8010257C;
    }
    // 0x80102514: nop

    // 0x80102518: jal         0x800C759C
    // 0x8010251C: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    getObjectiveBoolean(rdram, ctx);
        goto after_97;
    // 0x8010251C: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_97:
    // 0x80102520: addu        $s1, $v0, $zero
    ctx->r17 = ADD32(ctx->r2, 0);
    // 0x80102524: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80102528: bne         $s1, $v0, L_8010257C
    if (ctx->r17 != ctx->r2) {
        // 0x8010252C: nop
    
            goto L_8010257C;
    }
    // 0x8010252C: nop

    // 0x80102530: jal         0x800C759C
    // 0x80102534: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    getObjectiveBoolean(rdram, ctx);
        goto after_98;
    // 0x80102534: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    after_98:
    // 0x80102538: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // 0x8010253C: bne         $s0, $s1, L_8010257C
    if (ctx->r16 != ctx->r17) {
        // 0x80102540: nop
    
            goto L_8010257C;
    }
    // 0x80102540: nop

    // 0x80102544: jal         0x800C759C
    // 0x80102548: addiu       $a0, $zero, 0x63
    ctx->r4 = ADD32(0, 0X63);
    getObjectiveBoolean(rdram, ctx);
        goto after_99;
    // 0x80102548: addiu       $a0, $zero, 0x63
    ctx->r4 = ADD32(0, 0X63);
    after_99:
    // 0x8010254C: bne         $v0, $s0, L_8010257C
    if (ctx->r2 != ctx->r16) {
        // 0x80102550: nop
    
            goto L_8010257C;
    }
    // 0x80102550: nop

    // 0x80102554: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x80102558: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x8010255C: jal         0x800C76FC
    // 0x80102560: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    setObjectiveTimer(rdram, ctx);
        goto after_100;
    // 0x80102560: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_100:
    // 0x80102564: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80102568: jal         0x800C76FC
    // 0x8010256C: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    setObjectiveTimer(rdram, ctx);
        goto after_101;
    // 0x8010256C: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_101:
    // 0x80102570: addiu       $a0, $zero, 0x1F
    ctx->r4 = ADD32(0, 0X1F);
    // 0x80102574: jal         0x800C7540
    // 0x80102578: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    setObjectiveBoolean(rdram, ctx);
        goto after_102;
    // 0x80102578: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_102:
L_8010257C:
    // 0x8010257C: jal         0x800C759C
    // 0x80102580: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    getObjectiveBoolean(rdram, ctx);
        goto after_103;
    // 0x80102580: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    after_103:
    // 0x80102584: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x80102588: bne         $v0, $v1, L_801025B0
    if (ctx->r2 != ctx->r3) {
        // 0x8010258C: nop
    
            goto L_801025B0;
    }
    // 0x8010258C: nop

    // 0x80102590: jal         0x800C759C
    // 0x80102594: addiu       $a0, $zero, 0x66
    ctx->r4 = ADD32(0, 0X66);
    getObjectiveBoolean(rdram, ctx);
        goto after_104;
    // 0x80102594: addiu       $a0, $zero, 0x66
    ctx->r4 = ADD32(0, 0X66);
    after_104:
    // 0x80102598: bne         $v0, $zero, L_801025B0
    if (ctx->r2 != 0) {
        // 0x8010259C: addiu       $a0, $zero, 0x66
        ctx->r4 = ADD32(0, 0X66);
            goto L_801025B0;
    }
    // 0x8010259C: addiu       $a0, $zero, 0x66
    ctx->r4 = ADD32(0, 0X66);
    // 0x801025A0: jal         0x800C7540
    // 0x801025A4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    setObjectiveBoolean(rdram, ctx);
        goto after_105;
    // 0x801025A4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_105:
    // 0x801025A8: jal         0x800C76B0
    // 0x801025AC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    activateObjectiveCompleteFlag(rdram, ctx);
        goto after_106;
    // 0x801025AC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_106:
L_801025B0:
    // 0x801025B0: jal         0x800C759C
    // 0x801025B4: addiu       $a0, $zero, 0x1F
    ctx->r4 = ADD32(0, 0X1F);
    getObjectiveBoolean(rdram, ctx);
        goto after_107;
    // 0x801025B4: addiu       $a0, $zero, 0x1F
    ctx->r4 = ADD32(0, 0X1F);
    after_107:
    // 0x801025B8: bne         $v0, $zero, L_80102624
    if (ctx->r2 != 0) {
        // 0x801025BC: nop
    
            goto L_80102624;
    }
    // 0x801025BC: nop

    // 0x801025C0: jal         0x800C759C
    // 0x801025C4: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    getObjectiveBoolean(rdram, ctx);
        goto after_108;
    // 0x801025C4: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_108:
    // 0x801025C8: addu        $s1, $v0, $zero
    ctx->r17 = ADD32(ctx->r2, 0);
    // 0x801025CC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x801025D0: bne         $s1, $v0, L_80102624
    if (ctx->r17 != ctx->r2) {
        // 0x801025D4: nop
    
            goto L_80102624;
    }
    // 0x801025D4: nop

    // 0x801025D8: jal         0x800C759C
    // 0x801025DC: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    getObjectiveBoolean(rdram, ctx);
        goto after_109;
    // 0x801025DC: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    after_109:
    // 0x801025E0: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // 0x801025E4: bne         $s0, $s1, L_80102624
    if (ctx->r16 != ctx->r17) {
        // 0x801025E8: nop
    
            goto L_80102624;
    }
    // 0x801025E8: nop

    // 0x801025EC: jal         0x800C759C
    // 0x801025F0: addiu       $a0, $zero, 0x63
    ctx->r4 = ADD32(0, 0X63);
    getObjectiveBoolean(rdram, ctx);
        goto after_110;
    // 0x801025F0: addiu       $a0, $zero, 0x63
    ctx->r4 = ADD32(0, 0X63);
    after_110:
    // 0x801025F4: bne         $v0, $s0, L_80102624
    if (ctx->r2 != ctx->r16) {
        // 0x801025F8: nop
    
            goto L_80102624;
    }
    // 0x801025F8: nop

    // 0x801025FC: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x80102600: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80102604: jal         0x800C76FC
    // 0x80102608: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    setObjectiveTimer(rdram, ctx);
        goto after_111;
    // 0x80102608: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_111:
    // 0x8010260C: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80102610: jal         0x800C76FC
    // 0x80102614: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    setObjectiveTimer(rdram, ctx);
        goto after_112;
    // 0x80102614: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_112:
    // 0x80102618: addiu       $a0, $zero, 0x1F
    ctx->r4 = ADD32(0, 0X1F);
    // 0x8010261C: jal         0x800C7540
    // 0x80102620: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    setObjectiveBoolean(rdram, ctx);
        goto after_113;
    // 0x80102620: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_113:
L_80102624:
    // 0x80102624: jal         0x800C759C
    // 0x80102628: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    getObjectiveBoolean(rdram, ctx);
        goto after_114;
    // 0x80102628: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    after_114:
    // 0x8010262C: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x80102630: bne         $v0, $v1, L_80102658
    if (ctx->r2 != ctx->r3) {
        // 0x80102634: nop
    
            goto L_80102658;
    }
    // 0x80102634: nop

    // 0x80102638: jal         0x800C759C
    // 0x8010263C: addiu       $a0, $zero, 0x66
    ctx->r4 = ADD32(0, 0X66);
    getObjectiveBoolean(rdram, ctx);
        goto after_115;
    // 0x8010263C: addiu       $a0, $zero, 0x66
    ctx->r4 = ADD32(0, 0X66);
    after_115:
    // 0x80102640: bne         $v0, $zero, L_80102658
    if (ctx->r2 != 0) {
        // 0x80102644: addiu       $a0, $zero, 0x66
        ctx->r4 = ADD32(0, 0X66);
            goto L_80102658;
    }
    // 0x80102644: addiu       $a0, $zero, 0x66
    ctx->r4 = ADD32(0, 0X66);
    // 0x80102648: jal         0x800C7540
    // 0x8010264C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    setObjectiveBoolean(rdram, ctx);
        goto after_116;
    // 0x8010264C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_116:
    // 0x80102650: jal         0x800C76B0
    // 0x80102654: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    activateObjectiveCompleteFlag(rdram, ctx);
        goto after_117;
    // 0x80102654: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_117:
L_80102658:
    // 0x80102658: jal         0x800C759C
    // 0x8010265C: addiu       $a0, $zero, 0x1F
    ctx->r4 = ADD32(0, 0X1F);
    getObjectiveBoolean(rdram, ctx);
        goto after_118;
    // 0x8010265C: addiu       $a0, $zero, 0x1F
    ctx->r4 = ADD32(0, 0X1F);
    after_118:
    // 0x80102660: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // 0x80102664: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80102668: bne         $s0, $v0, L_801026B4
    if (ctx->r16 != ctx->r2) {
        // 0x8010266C: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_801026B4;
    }
    // 0x8010266C: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x80102670: jal         0x800C759C
    // 0x80102674: addiu       $a0, $zero, 0x20
    ctx->r4 = ADD32(0, 0X20);
    getObjectiveBoolean(rdram, ctx);
        goto after_119;
    // 0x80102674: addiu       $a0, $zero, 0x20
    ctx->r4 = ADD32(0, 0X20);
    after_119:
    // 0x80102678: addu        $s1, $v0, $zero
    ctx->r17 = ADD32(ctx->r2, 0);
    // 0x8010267C: bne         $s1, $s0, L_801026B4
    if (ctx->r17 != ctx->r16) {
        // 0x80102680: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_801026B4;
    }
    // 0x80102680: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x80102684: jal         0x800C759C
    // 0x80102688: addiu       $a0, $zero, 0x21
    ctx->r4 = ADD32(0, 0X21);
    getObjectiveBoolean(rdram, ctx);
        goto after_120;
    // 0x80102688: addiu       $a0, $zero, 0x21
    ctx->r4 = ADD32(0, 0X21);
    after_120:
    // 0x8010268C: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // 0x80102690: bne         $s0, $s1, L_801026B4
    if (ctx->r16 != ctx->r17) {
        // 0x80102694: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_801026B4;
    }
    // 0x80102694: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x80102698: jal         0x800C759C
    // 0x8010269C: addiu       $a0, $zero, 0x63
    ctx->r4 = ADD32(0, 0X63);
    getObjectiveBoolean(rdram, ctx);
        goto after_121;
    // 0x8010269C: addiu       $a0, $zero, 0x63
    ctx->r4 = ADD32(0, 0X63);
    after_121:
    // 0x801026A0: bne         $v0, $s0, L_801026B4
    if (ctx->r2 != ctx->r16) {
        // 0x801026A4: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_801026B4;
    }
    // 0x801026A4: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x801026A8: jal         0x800C776C
    // 0x801026AC: nop

    setHudEnableBit8(rdram, ctx);
        goto after_122;
    // 0x801026AC: nop

    after_122:
    // 0x801026B0: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_801026B4:
    // 0x801026B4: lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X18);
    // 0x801026B8: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x801026BC: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x801026C0: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x801026C4: jr          $ra
    // 0x801026C8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x801026C8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void playVoice2_0xA4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801026CC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801026D0: addiu       $a0, $zero, 0xA4
    ctx->r4 = ADD32(0, 0XA4);
    // 0x801026D4: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x801026D8: jal         0x800C7D1C
    // 0x801026DC: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    playObjectiveVoiceLine2(rdram, ctx);
        goto after_0;
    // 0x801026DC: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_0:
    // 0x801026E0: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x801026E4: jr          $ra
    // 0x801026E8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x801026E8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void playVoice2_0x139(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801026EC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801026F0: addiu       $a0, $zero, 0x139
    ctx->r4 = ADD32(0, 0X139);
    // 0x801026F4: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x801026F8: jal         0x800C7D1C
    // 0x801026FC: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    playObjectiveVoiceLine2(rdram, ctx);
        goto after_0;
    // 0x801026FC: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_0:
    // 0x80102700: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80102704: jr          $ra
    // 0x80102708: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80102708: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void playVoice2_0x139_v2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010270C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80102710: addiu       $a0, $zero, 0x139
    ctx->r4 = ADD32(0, 0X139);
    // 0x80102714: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80102718: jal         0x800C7D1C
    // 0x8010271C: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    playObjectiveVoiceLine2(rdram, ctx);
        goto after_0;
    // 0x8010271C: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_0:
    // 0x80102720: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80102724: jr          $ra
    // 0x80102728: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80102728: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void playVoice2_0x139_v3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010272C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80102730: addiu       $a0, $zero, 0x139
    ctx->r4 = ADD32(0, 0X139);
    // 0x80102734: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80102738: jal         0x800C7D1C
    // 0x8010273C: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    playObjectiveVoiceLine2(rdram, ctx);
        goto after_0;
    // 0x8010273C: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_0:
    // 0x80102740: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80102744: jr          $ra
    // 0x80102748: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80102748: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void playVoice2_0x139_v4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010274C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80102750: addiu       $a0, $zero, 0x1F5
    ctx->r4 = ADD32(0, 0X1F5);
    // 0x80102754: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80102758: jal         0x800C7D1C
    // 0x8010275C: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    playObjectiveVoiceLine2(rdram, ctx);
        goto after_0;
    // 0x8010275C: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_0:
    // 0x80102760: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80102764: jr          $ra
    // 0x80102768: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80102768: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void playVoice2_0x139_v5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010276C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80102770: addiu       $a0, $zero, 0x1F5
    ctx->r4 = ADD32(0, 0X1F5);
    // 0x80102774: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80102778: jal         0x800C7D1C
    // 0x8010277C: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    playObjectiveVoiceLine2(rdram, ctx);
        goto after_0;
    // 0x8010277C: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_0:
    // 0x80102780: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80102784: jr          $ra
    // 0x80102788: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80102788: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void playVoice2_0x139_v6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010278C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80102790: addiu       $a0, $zero, 0x1F5
    ctx->r4 = ADD32(0, 0X1F5);
    // 0x80102794: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80102798: jal         0x800C7D1C
    // 0x8010279C: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    playObjectiveVoiceLine2(rdram, ctx);
        goto after_0;
    // 0x8010279C: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_0:
    // 0x801027A0: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x801027A4: jr          $ra
    // 0x801027A8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x801027A8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void lv3_runDialogueSequenceB(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801027AC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801027B0: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x801027B4: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x801027B8: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x801027BC: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x801027C0: jal         0x800C7D1C
    // 0x801027C4: addiu       $a0, $zero, 0x138
    ctx->r4 = ADD32(0, 0X138);
    playObjectiveVoiceLine2(rdram, ctx);
        goto after_0;
    // 0x801027C4: addiu       $a0, $zero, 0x138
    ctx->r4 = ADD32(0, 0X138);
    after_0:
    // 0x801027C8: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x801027CC: jal         0x800C7D1C
    // 0x801027D0: addiu       $a0, $zero, 0x1EF
    ctx->r4 = ADD32(0, 0X1EF);
    playObjectiveVoiceLine2(rdram, ctx);
        goto after_1;
    // 0x801027D0: addiu       $a0, $zero, 0x1EF
    ctx->r4 = ADD32(0, 0X1EF);
    after_1:
    // 0x801027D4: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    // 0x801027D8: jal         0x800C7D1C
    // 0x801027DC: addiu       $a0, $zero, 0x10D
    ctx->r4 = ADD32(0, 0X10D);
    playObjectiveVoiceLine2(rdram, ctx);
        goto after_2;
    // 0x801027DC: addiu       $a0, $zero, 0x10D
    ctx->r4 = ADD32(0, 0X10D);
    after_2:
    // 0x801027E0: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x801027E4: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x801027E8: jr          $ra
    // 0x801027EC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x801027EC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void lv3_runDialogueSequenceC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801027F0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801027F4: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x801027F8: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x801027FC: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80102800: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80102804: jal         0x800C7D1C
    // 0x80102808: addiu       $a0, $zero, 0x138
    ctx->r4 = ADD32(0, 0X138);
    playObjectiveVoiceLine2(rdram, ctx);
        goto after_0;
    // 0x80102808: addiu       $a0, $zero, 0x138
    ctx->r4 = ADD32(0, 0X138);
    after_0:
    // 0x8010280C: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80102810: jal         0x800C7D1C
    // 0x80102814: addiu       $a0, $zero, 0x1EF
    ctx->r4 = ADD32(0, 0X1EF);
    playObjectiveVoiceLine2(rdram, ctx);
        goto after_1;
    // 0x80102814: addiu       $a0, $zero, 0x1EF
    ctx->r4 = ADD32(0, 0X1EF);
    after_1:
    // 0x80102818: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    // 0x8010281C: jal         0x800C7D1C
    // 0x80102820: addiu       $a0, $zero, 0x10D
    ctx->r4 = ADD32(0, 0X10D);
    playObjectiveVoiceLine2(rdram, ctx);
        goto after_2;
    // 0x80102820: addiu       $a0, $zero, 0x10D
    ctx->r4 = ADD32(0, 0X10D);
    after_2:
    // 0x80102824: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80102828: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x8010282C: jr          $ra
    // 0x80102830: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80102830: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void lv3_runDialogueSequenceD(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80102834: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80102838: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x8010283C: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x80102840: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80102844: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80102848: jal         0x800C7D1C
    // 0x8010284C: addiu       $a0, $zero, 0x138
    ctx->r4 = ADD32(0, 0X138);
    playObjectiveVoiceLine2(rdram, ctx);
        goto after_0;
    // 0x8010284C: addiu       $a0, $zero, 0x138
    ctx->r4 = ADD32(0, 0X138);
    after_0:
    // 0x80102850: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80102854: jal         0x800C7D1C
    // 0x80102858: addiu       $a0, $zero, 0x1EF
    ctx->r4 = ADD32(0, 0X1EF);
    playObjectiveVoiceLine2(rdram, ctx);
        goto after_1;
    // 0x80102858: addiu       $a0, $zero, 0x1EF
    ctx->r4 = ADD32(0, 0X1EF);
    after_1:
    // 0x8010285C: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    // 0x80102860: jal         0x800C7D1C
    // 0x80102864: addiu       $a0, $zero, 0x10D
    ctx->r4 = ADD32(0, 0X10D);
    playObjectiveVoiceLine2(rdram, ctx);
        goto after_2;
    // 0x80102864: addiu       $a0, $zero, 0x10D
    ctx->r4 = ADD32(0, 0X10D);
    after_2:
    // 0x80102868: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x8010286C: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x80102870: jr          $ra
    // 0x80102874: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80102874: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void lv3_dialogueWithStateA(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80102878: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8010287C: lui         $a1, 0x4040
    ctx->r5 = S32(0X4040 << 16);
    // 0x80102880: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80102884: jal         0x800C7D1C
    // 0x80102888: addiu       $a0, $zero, 0x53
    ctx->r4 = ADD32(0, 0X53);
    playObjectiveVoiceLine2(rdram, ctx);
        goto after_0;
    // 0x80102888: addiu       $a0, $zero, 0x53
    ctx->r4 = ADD32(0, 0X53);
    after_0:
    // 0x8010288C: lui         $a1, 0x3F00
    ctx->r5 = S32(0X3F00 << 16);
    // 0x80102890: jal         0x800C7D1C
    // 0x80102894: addiu       $a0, $zero, 0x25
    ctx->r4 = ADD32(0, 0X25);
    playObjectiveVoiceLine2(rdram, ctx);
        goto after_1;
    // 0x80102894: addiu       $a0, $zero, 0x25
    ctx->r4 = ADD32(0, 0X25);
    after_1:
    // 0x80102898: addiu       $a0, $zero, 0x6E
    ctx->r4 = ADD32(0, 0X6E);
    // 0x8010289C: jal         0x800C7540
    // 0x801028A0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    setObjectiveBoolean(rdram, ctx);
        goto after_2;
    // 0x801028A0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
    // 0x801028A4: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x801028A8: jr          $ra
    // 0x801028AC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x801028AC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void lv3_dialogueWithStateB(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801028B0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801028B4: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x801028B8: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x801028BC: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x801028C0: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x801028C4: jal         0x800C7D1C
    // 0x801028C8: addiu       $a0, $zero, 0x53
    ctx->r4 = ADD32(0, 0X53);
    playObjectiveVoiceLine2(rdram, ctx);
        goto after_0;
    // 0x801028C8: addiu       $a0, $zero, 0x53
    ctx->r4 = ADD32(0, 0X53);
    after_0:
    // 0x801028CC: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x801028D0: jal         0x800C7D1C
    // 0x801028D4: addiu       $a0, $zero, 0x25
    ctx->r4 = ADD32(0, 0X25);
    playObjectiveVoiceLine2(rdram, ctx);
        goto after_1;
    // 0x801028D4: addiu       $a0, $zero, 0x25
    ctx->r4 = ADD32(0, 0X25);
    after_1:
    // 0x801028D8: addiu       $a0, $zero, 0x6F
    ctx->r4 = ADD32(0, 0X6F);
    // 0x801028DC: jal         0x800C7540
    // 0x801028E0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    setObjectiveBoolean(rdram, ctx);
        goto after_2;
    // 0x801028E0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
    // 0x801028E4: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x801028E8: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x801028EC: jr          $ra
    // 0x801028F0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x801028F0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void lv3_dialogueWithStateC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801028F4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801028F8: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x801028FC: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x80102900: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80102904: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80102908: jal         0x800C7D1C
    // 0x8010290C: addiu       $a0, $zero, 0x53
    ctx->r4 = ADD32(0, 0X53);
    playObjectiveVoiceLine2(rdram, ctx);
        goto after_0;
    // 0x8010290C: addiu       $a0, $zero, 0x53
    ctx->r4 = ADD32(0, 0X53);
    after_0:
    // 0x80102910: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80102914: jal         0x800C7D1C
    // 0x80102918: addiu       $a0, $zero, 0x25
    ctx->r4 = ADD32(0, 0X25);
    playObjectiveVoiceLine2(rdram, ctx);
        goto after_1;
    // 0x80102918: addiu       $a0, $zero, 0x25
    ctx->r4 = ADD32(0, 0X25);
    after_1:
    // 0x8010291C: addiu       $a0, $zero, 0x70
    ctx->r4 = ADD32(0, 0X70);
    // 0x80102920: jal         0x800C7540
    // 0x80102924: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    setObjectiveBoolean(rdram, ctx);
        goto after_2;
    // 0x80102924: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
    // 0x80102928: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x8010292C: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x80102930: jr          $ra
    // 0x80102934: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80102934: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void scheduleLv3DialogueWithHudA_1_5s(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80102938: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8010293C: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x80102940: lui         $a1, 0x3FC0
    ctx->r5 = S32(0X3FC0 << 16);
    // 0x80102944: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80102948: jal         0x800C7864
    // 0x8010294C: addiu       $a0, $a0, 0x295C
    ctx->r4 = ADD32(ctx->r4, 0X295C);
    addTimerHandleWrapper(rdram, ctx);
        goto after_0;
    // 0x8010294C: addiu       $a0, $a0, 0x295C
    ctx->r4 = ADD32(ctx->r4, 0X295C);
    after_0:
    // 0x80102950: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80102954: jr          $ra
    // 0x80102958: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80102958: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void lv3_dialogueWithHudUpdateA(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010295C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80102960: addiu       $a0, $zero, 0x11D
    ctx->r4 = ADD32(0, 0X11D);
    // 0x80102964: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80102968: jal         0x800C7D1C
    // 0x8010296C: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    playObjectiveVoiceLine2(rdram, ctx);
        goto after_0;
    // 0x8010296C: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_0:
    // 0x80102970: lui         $a1, 0x3F00
    ctx->r5 = S32(0X3F00 << 16);
    // 0x80102974: jal         0x800C7D1C
    // 0x80102978: addiu       $a0, $zero, 0x1E3
    ctx->r4 = ADD32(0, 0X1E3);
    playObjectiveVoiceLine2(rdram, ctx);
        goto after_1;
    // 0x80102978: addiu       $a0, $zero, 0x1E3
    ctx->r4 = ADD32(0, 0X1E3);
    after_1:
    // 0x8010297C: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x80102980: jal         0x800C7884
    // 0x80102984: addiu       $a0, $a0, -0x6A04
    ctx->r4 = ADD32(ctx->r4, -0X6A04);
    setHudFlagBit40AndStoreArg(rdram, ctx);
        goto after_2;
    // 0x80102984: addiu       $a0, $a0, -0x6A04
    ctx->r4 = ADD32(ctx->r4, -0X6A04);
    after_2:
    // 0x80102988: jal         0x800C7D98
    // 0x8010298C: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    triggerSoundCueByType(rdram, ctx);
        goto after_3;
    // 0x8010298C: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_3:
    // 0x80102990: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80102994: jr          $ra
    // 0x80102998: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80102998: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void scheduleLv3DialogueWithHudB_1_5s(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010299C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801029A0: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x801029A4: lui         $a1, 0x3FC0
    ctx->r5 = S32(0X3FC0 << 16);
    // 0x801029A8: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x801029AC: jal         0x800C7864
    // 0x801029B0: addiu       $a0, $a0, 0x29C0
    ctx->r4 = ADD32(ctx->r4, 0X29C0);
    addTimerHandleWrapper(rdram, ctx);
        goto after_0;
    // 0x801029B0: addiu       $a0, $a0, 0x29C0
    ctx->r4 = ADD32(ctx->r4, 0X29C0);
    after_0:
    // 0x801029B4: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x801029B8: jr          $ra
    // 0x801029BC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x801029BC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void lv3_dialogueWithHudUpdateB(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801029C0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801029C4: addiu       $a0, $zero, 0x11D
    ctx->r4 = ADD32(0, 0X11D);
    // 0x801029C8: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x801029CC: jal         0x800C7D1C
    // 0x801029D0: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    playObjectiveVoiceLine2(rdram, ctx);
        goto after_0;
    // 0x801029D0: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_0:
    // 0x801029D4: lui         $a1, 0x3F00
    ctx->r5 = S32(0X3F00 << 16);
    // 0x801029D8: jal         0x800C7D1C
    // 0x801029DC: addiu       $a0, $zero, 0x1E3
    ctx->r4 = ADD32(0, 0X1E3);
    playObjectiveVoiceLine2(rdram, ctx);
        goto after_1;
    // 0x801029DC: addiu       $a0, $zero, 0x1E3
    ctx->r4 = ADD32(0, 0X1E3);
    after_1:
    // 0x801029E0: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x801029E4: jal         0x800C7884
    // 0x801029E8: addiu       $a0, $a0, -0x69F8
    ctx->r4 = ADD32(ctx->r4, -0X69F8);
    setHudFlagBit40AndStoreArg(rdram, ctx);
        goto after_2;
    // 0x801029E8: addiu       $a0, $a0, -0x69F8
    ctx->r4 = ADD32(ctx->r4, -0X69F8);
    after_2:
    // 0x801029EC: jal         0x800C7D98
    // 0x801029F0: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    triggerSoundCueByType(rdram, ctx);
        goto after_3;
    // 0x801029F0: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_3:
    // 0x801029F4: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x801029F8: jr          $ra
    // 0x801029FC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x801029FC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void scheduleLv3DialogueWithHudC_1_5s(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80102A00: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80102A04: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x80102A08: lui         $a1, 0x3FC0
    ctx->r5 = S32(0X3FC0 << 16);
    // 0x80102A0C: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80102A10: jal         0x800C7864
    // 0x80102A14: addiu       $a0, $a0, 0x2A24
    ctx->r4 = ADD32(ctx->r4, 0X2A24);
    addTimerHandleWrapper(rdram, ctx);
        goto after_0;
    // 0x80102A14: addiu       $a0, $a0, 0x2A24
    ctx->r4 = ADD32(ctx->r4, 0X2A24);
    after_0:
    // 0x80102A18: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80102A1C: jr          $ra
    // 0x80102A20: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80102A20: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void lv3_dialogueWithHudUpdateC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80102A24: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80102A28: addiu       $a0, $zero, 0x11D
    ctx->r4 = ADD32(0, 0X11D);
    // 0x80102A2C: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80102A30: jal         0x800C7D1C
    // 0x80102A34: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    playObjectiveVoiceLine2(rdram, ctx);
        goto after_0;
    // 0x80102A34: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_0:
    // 0x80102A38: lui         $a1, 0x3F00
    ctx->r5 = S32(0X3F00 << 16);
    // 0x80102A3C: jal         0x800C7D1C
    // 0x80102A40: addiu       $a0, $zero, 0x1E3
    ctx->r4 = ADD32(0, 0X1E3);
    playObjectiveVoiceLine2(rdram, ctx);
        goto after_1;
    // 0x80102A40: addiu       $a0, $zero, 0x1E3
    ctx->r4 = ADD32(0, 0X1E3);
    after_1:
    // 0x80102A44: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x80102A48: jal         0x800C7884
    // 0x80102A4C: addiu       $a0, $a0, -0x69EC
    ctx->r4 = ADD32(ctx->r4, -0X69EC);
    setHudFlagBit40AndStoreArg(rdram, ctx);
        goto after_2;
    // 0x80102A4C: addiu       $a0, $a0, -0x69EC
    ctx->r4 = ADD32(ctx->r4, -0X69EC);
    after_2:
    // 0x80102A50: jal         0x800C7D98
    // 0x80102A54: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    triggerSoundCueByType(rdram, ctx);
        goto after_3;
    // 0x80102A54: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_3:
    // 0x80102A58: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80102A5C: jr          $ra
    // 0x80102A60: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80102A60: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void lv2_objectiveSlot1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80102A64: jr          $ra
    // 0x80102A68: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    return;
    // 0x80102A68: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
;}
RECOMP_FUNC void lv2_calculateFriendliesSaved(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80102A6C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80102A70: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80102A74: jal         0x800C761C
    // 0x80102A78: addiu       $a0, $zero, 0x28
    ctx->r4 = ADD32(0, 0X28);
    getObjectiveCount(rdram, ctx);
        goto after_0;
    // 0x80102A78: addiu       $a0, $zero, 0x28
    ctx->r4 = ADD32(0, 0X28);
    after_0:
    // 0x80102A7C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80102A80: jal         0x800C77B0
    // 0x80102A84: subu        $a0, $a0, $v0
    ctx->r4 = SUB32(ctx->r4, ctx->r2);
    setFriendliesSaved(rdram, ctx);
        goto after_1;
    // 0x80102A84: subu        $a0, $a0, $v0
    ctx->r4 = SUB32(ctx->r4, ctx->r2);
    after_1:
    // 0x80102A88: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80102A8C: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x80102A90: jr          $ra
    // 0x80102A94: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80102A94: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void fake_func_80102A98(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
;}
RECOMP_FUNC void lv3_initializeObjectTracking(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80102AA0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80102AA4: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80102AA8: lwc1        $f12, -0x69E0($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X69E0);
    // 0x80102AAC: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80102AB0: sw          $zero, -0x2FB0($v0)
    MEM_W(-0X2FB0, ctx->r2) = 0;
    // 0x80102AB4: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80102AB8: sw          $ra, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r31;
    // 0x80102ABC: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80102AC0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80102AC4: jal         0x800C7CEC
    // 0x80102AC8: sw          $zero, -0x2FAC($v0)
    MEM_W(-0X2FAC, ctx->r2) = 0;
    setLevelObjectTrackingScalar(rdram, ctx);
        goto after_0;
    // 0x80102AC8: sw          $zero, -0x2FAC($v0)
    MEM_W(-0X2FAC, ctx->r2) = 0;
    after_0:
    // 0x80102ACC: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x80102AD0: addiu       $a0, $a0, 0x3360
    ctx->r4 = ADD32(ctx->r4, 0X3360);
    // 0x80102AD4: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80102AD8: addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    // 0x80102ADC: addiu       $a3, $zero, 0x19
    ctx->r7 = ADD32(0, 0X19);
    // 0x80102AE0: addiu       $s1, $zero, 0x2
    ctx->r17 = ADD32(0, 0X2);
    // 0x80102AE4: jal         0x800C7830
    // 0x80102AE8: sw          $s1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r17;
    addBooleanCountHandleWrapper(rdram, ctx);
        goto after_1;
    // 0x80102AE8: sw          $s1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r17;
    after_1:
    // 0x80102AEC: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x80102AF0: addiu       $a0, $a0, 0x3424
    ctx->r4 = ADD32(ctx->r4, 0X3424);
    // 0x80102AF4: addiu       $a1, $zero, 0x1A
    ctx->r5 = ADD32(0, 0X1A);
    // 0x80102AF8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80102AFC: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // 0x80102B00: jal         0x800C7830
    // 0x80102B04: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    addBooleanCountHandleWrapper(rdram, ctx);
        goto after_2;
    // 0x80102B04: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_2:
    // 0x80102B08: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x80102B0C: addiu       $a0, $a0, 0x3464
    ctx->r4 = ADD32(ctx->r4, 0X3464);
    // 0x80102B10: addiu       $a1, $zero, 0x1C
    ctx->r5 = ADD32(0, 0X1C);
    // 0x80102B14: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80102B18: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // 0x80102B1C: jal         0x800C7830
    // 0x80102B20: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    addBooleanCountHandleWrapper(rdram, ctx);
        goto after_3;
    // 0x80102B20: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_3:
    // 0x80102B24: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x80102B28: addiu       $a0, $a0, 0x3340
    ctx->r4 = ADD32(ctx->r4, 0X3340);
    // 0x80102B2C: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80102B30: addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    // 0x80102B34: addiu       $a3, $zero, 0x12
    ctx->r7 = ADD32(0, 0X12);
    // 0x80102B38: jal         0x800C7830
    // 0x80102B3C: sw          $s1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r17;
    addBooleanCountHandleWrapper(rdram, ctx);
        goto after_4;
    // 0x80102B3C: sw          $s1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r17;
    after_4:
    // 0x80102B40: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x80102B44: addiu       $a0, $a0, 0x3110
    ctx->r4 = ADD32(ctx->r4, 0X3110);
    // 0x80102B48: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80102B4C: addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    // 0x80102B50: addiu       $a3, $zero, 0x5
    ctx->r7 = ADD32(0, 0X5);
    // 0x80102B54: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
    // 0x80102B58: jal         0x800C7830
    // 0x80102B5C: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    addBooleanCountHandleWrapper(rdram, ctx);
        goto after_5;
    // 0x80102B5C: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    after_5:
    // 0x80102B60: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x80102B64: addiu       $a0, $a0, 0x2F34
    ctx->r4 = ADD32(ctx->r4, 0X2F34);
    // 0x80102B68: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80102B6C: addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    // 0x80102B70: addiu       $a3, $zero, 0x1D
    ctx->r7 = ADD32(0, 0X1D);
    // 0x80102B74: addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
    // 0x80102B78: jal         0x800C7830
    // 0x80102B7C: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    addBooleanCountHandleWrapper(rdram, ctx);
        goto after_6;
    // 0x80102B7C: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    after_6:
    // 0x80102B80: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x80102B84: addiu       $a0, $a0, 0x3010
    ctx->r4 = ADD32(ctx->r4, 0X3010);
    // 0x80102B88: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80102B8C: addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    // 0x80102B90: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    // 0x80102B94: jal         0x800C7830
    // 0x80102B98: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    addBooleanCountHandleWrapper(rdram, ctx);
        goto after_7;
    // 0x80102B98: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    after_7:
    // 0x80102B9C: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x80102BA0: addiu       $a0, $a0, 0x30B8
    ctx->r4 = ADD32(ctx->r4, 0X30B8);
    // 0x80102BA4: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80102BA8: addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    // 0x80102BAC: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    // 0x80102BB0: jal         0x800C7830
    // 0x80102BB4: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    addBooleanCountHandleWrapper(rdram, ctx);
        goto after_8;
    // 0x80102BB4: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    after_8:
    // 0x80102BB8: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x80102BBC: addiu       $a0, $a0, 0x30F0
    ctx->r4 = ADD32(ctx->r4, 0X30F0);
    // 0x80102BC0: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80102BC4: addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    // 0x80102BC8: addiu       $a3, $zero, 0xA
    ctx->r7 = ADD32(0, 0XA);
    // 0x80102BCC: jal         0x800C7830
    // 0x80102BD0: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    addBooleanCountHandleWrapper(rdram, ctx);
        goto after_9;
    // 0x80102BD0: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    after_9:
    // 0x80102BD4: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x80102BD8: addiu       $a0, $a0, 0x32B4
    ctx->r4 = ADD32(ctx->r4, 0X32B4);
    // 0x80102BDC: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80102BE0: addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    // 0x80102BE4: addiu       $a3, $zero, 0xE
    ctx->r7 = ADD32(0, 0XE);
    // 0x80102BE8: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x80102BEC: jal         0x800C7830
    // 0x80102BF0: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    addBooleanCountHandleWrapper(rdram, ctx);
        goto after_10;
    // 0x80102BF0: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    after_10:
    // 0x80102BF4: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x80102BF8: addiu       $a0, $a0, 0x32F0
    ctx->r4 = ADD32(ctx->r4, 0X32F0);
    // 0x80102BFC: addiu       $a1, $zero, 0x11
    ctx->r5 = ADD32(0, 0X11);
    // 0x80102C00: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    // 0x80102C04: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // 0x80102C08: jal         0x800C7830
    // 0x80102C0C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    addBooleanCountHandleWrapper(rdram, ctx);
        goto after_11;
    // 0x80102C0C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_11:
    // 0x80102C10: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x80102C14: addiu       $a0, $a0, 0x313C
    ctx->r4 = ADD32(ctx->r4, 0X313C);
    // 0x80102C18: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80102C1C: addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    // 0x80102C20: addiu       $a3, $zero, 0x13
    ctx->r7 = ADD32(0, 0X13);
    // 0x80102C24: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
    // 0x80102C28: jal         0x800C7830
    // 0x80102C2C: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    addBooleanCountHandleWrapper(rdram, ctx);
        goto after_12;
    // 0x80102C2C: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    after_12:
    // 0x80102C30: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x80102C34: addiu       $a0, $a0, 0x33EC
    ctx->r4 = ADD32(ctx->r4, 0X33EC);
    // 0x80102C38: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80102C3C: addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    // 0x80102C40: addiu       $a3, $zero, 0x15
    ctx->r7 = ADD32(0, 0X15);
    // 0x80102C44: jal         0x800C7830
    // 0x80102C48: sw          $s1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r17;
    addBooleanCountHandleWrapper(rdram, ctx);
        goto after_13;
    // 0x80102C48: sw          $s1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r17;
    after_13:
    // 0x80102C4C: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x80102C50: addiu       $a0, $a0, 0x349C
    ctx->r4 = ADD32(ctx->r4, 0X349C);
    // 0x80102C54: addiu       $a1, $zero, 0x24
    ctx->r5 = ADD32(0, 0X24);
    // 0x80102C58: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    // 0x80102C5C: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // 0x80102C60: jal         0x800C7830
    // 0x80102C64: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    addBooleanCountHandleWrapper(rdram, ctx);
        goto after_14;
    // 0x80102C64: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_14:
    // 0x80102C68: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x80102C6C: addiu       $a0, $a0, 0x34C0
    ctx->r4 = ADD32(ctx->r4, 0X34C0);
    // 0x80102C70: addiu       $a1, $zero, 0x25
    ctx->r5 = ADD32(0, 0X25);
    // 0x80102C74: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    // 0x80102C78: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // 0x80102C7C: jal         0x800C7830
    // 0x80102C80: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    addBooleanCountHandleWrapper(rdram, ctx);
        goto after_15;
    // 0x80102C80: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_15:
    // 0x80102C84: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x80102C88: addiu       $a0, $a0, 0x34E4
    ctx->r4 = ADD32(ctx->r4, 0X34E4);
    // 0x80102C8C: addiu       $a1, $zero, 0x26
    ctx->r5 = ADD32(0, 0X26);
    // 0x80102C90: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    // 0x80102C94: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // 0x80102C98: jal         0x800C7830
    // 0x80102C9C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    addBooleanCountHandleWrapper(rdram, ctx);
        goto after_16;
    // 0x80102C9C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_16:
    // 0x80102CA0: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x80102CA4: jal         0x800C7660
    // 0x80102CA8: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    setObjectiveHiddenFlag(rdram, ctx);
        goto after_17;
    // 0x80102CA8: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    after_17:
    // 0x80102CAC: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x80102CB0: jal         0x800C7660
    // 0x80102CB4: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    setObjectiveHiddenFlag(rdram, ctx);
        goto after_18;
    // 0x80102CB4: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    after_18:
    // 0x80102CB8: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x80102CBC: jal         0x800C7660
    // 0x80102CC0: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    setObjectiveHiddenFlag(rdram, ctx);
        goto after_19;
    // 0x80102CC0: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_19:
    // 0x80102CC4: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x80102CC8: jal         0x800C7660
    // 0x80102CCC: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    setObjectiveHiddenFlag(rdram, ctx);
        goto after_20;
    // 0x80102CCC: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_20:
    // 0x80102CD0: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x80102CD4: addiu       $a0, $a0, 0x3508
    ctx->r4 = ADD32(ctx->r4, 0X3508);
    // 0x80102CD8: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80102CDC: addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    // 0x80102CE0: addiu       $a3, $zero, 0x6F
    ctx->r7 = ADD32(0, 0X6F);
    // 0x80102CE4: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x80102CE8: jal         0x800C7830
    // 0x80102CEC: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    addBooleanCountHandleWrapper(rdram, ctx);
        goto after_21;
    // 0x80102CEC: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    after_21:
    // 0x80102CF0: lw          $ra, 0x20($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X20);
    // 0x80102CF4: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80102CF8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80102CFC: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x80102D00: jr          $ra
    // 0x80102D04: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80102D04: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void lv3_checkComplexObjectives(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80102D08: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80102D0C: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80102D10: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x80102D14: jal         0x800C759C
    // 0x80102D18: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    getObjectiveBoolean(rdram, ctx);
        goto after_0;
    // 0x80102D18: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    after_0:
    // 0x80102D1C: blez        $v0, L_80102D78
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80102D20: lui         $v1, 0x8011
        ctx->r3 = S32(0X8011 << 16);
            goto L_80102D78;
    }
    // 0x80102D20: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x80102D24: lw          $v0, -0x2FB0($v1)
    ctx->r2 = MEM_W(ctx->r3, -0X2FB0);
    // 0x80102D28: bne         $v0, $zero, L_80102D78
    if (ctx->r2 != 0) {
        // 0x80102D2C: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80102D78;
    }
    // 0x80102D2C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80102D30: jal         0x800C7738
    // 0x80102D34: sw          $v0, -0x2FB0($v1)
    MEM_W(-0X2FB0, ctx->r3) = ctx->r2;
    setHudEnableBit4(rdram, ctx);
        goto after_1;
    // 0x80102D34: sw          $v0, -0x2FB0($v1)
    MEM_W(-0X2FB0, ctx->r3) = ctx->r2;
    after_1:
    // 0x80102D38: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x80102D3C: addiu       $a0, $a0, -0x69DC
    ctx->r4 = ADD32(ctx->r4, -0X69DC);
    // 0x80102D40: lui         $a1, 0x1
    ctx->r5 = S32(0X1 << 16);
    // 0x80102D44: jal         0x800C7390
    // 0x80102D48: ori         $a1, $a1, 0x869F
    ctx->r5 = ctx->r5 | 0X869F;
    dealDamagetoDatItem(rdram, ctx);
        goto after_2;
    // 0x80102D48: ori         $a1, $a1, 0x869F
    ctx->r5 = ctx->r5 | 0X869F;
    after_2:
    // 0x80102D4C: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x80102D50: addiu       $a0, $a0, -0x69C8
    ctx->r4 = ADD32(ctx->r4, -0X69C8);
    // 0x80102D54: lui         $a1, 0x1
    ctx->r5 = S32(0X1 << 16);
    // 0x80102D58: jal         0x800C7390
    // 0x80102D5C: ori         $a1, $a1, 0x869F
    ctx->r5 = ctx->r5 | 0X869F;
    dealDamagetoDatItem(rdram, ctx);
        goto after_3;
    // 0x80102D5C: ori         $a1, $a1, 0x869F
    ctx->r5 = ctx->r5 | 0X869F;
    after_3:
    // 0x80102D60: addiu       $a0, $zero, 0x140
    ctx->r4 = ADD32(0, 0X140);
    // 0x80102D64: jal         0x800C7D1C
    // 0x80102D68: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    playObjectiveVoiceLine2(rdram, ctx);
        goto after_4;
    // 0x80102D68: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_4:
    // 0x80102D6C: lui         $a1, 0x3F00
    ctx->r5 = S32(0X3F00 << 16);
    // 0x80102D70: jal         0x800C7D1C
    // 0x80102D74: addiu       $a0, $zero, 0x14B
    ctx->r4 = ADD32(0, 0X14B);
    playObjectiveVoiceLine2(rdram, ctx);
        goto after_5;
    // 0x80102D74: addiu       $a0, $zero, 0x14B
    ctx->r4 = ADD32(0, 0X14B);
    after_5:
L_80102D78:
    // 0x80102D78: jal         0x800C759C
    // 0x80102D7C: addiu       $a0, $zero, 0x12
    ctx->r4 = ADD32(0, 0X12);
    getObjectiveBoolean(rdram, ctx);
        goto after_6;
    // 0x80102D7C: addiu       $a0, $zero, 0x12
    ctx->r4 = ADD32(0, 0X12);
    after_6:
    // 0x80102D80: blez        $v0, L_80102DC4
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80102D84: lui         $v1, 0x8011
        ctx->r3 = S32(0X8011 << 16);
            goto L_80102DC4;
    }
    // 0x80102D84: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x80102D88: lw          $v0, -0x2FB0($v1)
    ctx->r2 = MEM_W(ctx->r3, -0X2FB0);
    // 0x80102D8C: bne         $v0, $zero, L_80102DC4
    if (ctx->r2 != 0) {
        // 0x80102D90: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80102DC4;
    }
    // 0x80102D90: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80102D94: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x80102D98: jal         0x800C7738
    // 0x80102D9C: sw          $v0, -0x2FB0($v1)
    MEM_W(-0X2FB0, ctx->r3) = ctx->r2;
    setHudEnableBit4(rdram, ctx);
        goto after_7;
    // 0x80102D9C: sw          $v0, -0x2FB0($v1)
    MEM_W(-0X2FB0, ctx->r3) = ctx->r2;
    after_7:
    // 0x80102DA0: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80102DA4: jal         0x800C7D1C
    // 0x80102DA8: addiu       $a0, $zero, 0x237
    ctx->r4 = ADD32(0, 0X237);
    playObjectiveVoiceLine2(rdram, ctx);
        goto after_8;
    // 0x80102DA8: addiu       $a0, $zero, 0x237
    ctx->r4 = ADD32(0, 0X237);
    after_8:
    // 0x80102DAC: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80102DB0: jal         0x800C7D1C
    // 0x80102DB4: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    playObjectiveVoiceLine2(rdram, ctx);
        goto after_9;
    // 0x80102DB4: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    after_9:
    // 0x80102DB8: lui         $a1, 0x3F00
    ctx->r5 = S32(0X3F00 << 16);
    // 0x80102DBC: jal         0x800C7D1C
    // 0x80102DC0: addiu       $a0, $zero, 0x5D
    ctx->r4 = ADD32(0, 0X5D);
    playObjectiveVoiceLine2(rdram, ctx);
        goto after_10;
    // 0x80102DC0: addiu       $a0, $zero, 0x5D
    ctx->r4 = ADD32(0, 0X5D);
    after_10:
L_80102DC4:
    // 0x80102DC4: jal         0x800C761C
    // 0x80102DC8: addiu       $a0, $zero, 0x16
    ctx->r4 = ADD32(0, 0X16);
    getObjectiveCount(rdram, ctx);
        goto after_11;
    // 0x80102DC8: addiu       $a0, $zero, 0x16
    ctx->r4 = ADD32(0, 0X16);
    after_11:
    // 0x80102DCC: blez        $v0, L_80102E00
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80102DD0: nop
    
            goto L_80102E00;
    }
    // 0x80102DD0: nop

    // 0x80102DD4: jal         0x800C76B0
    // 0x80102DD8: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    activateObjectiveCompleteFlag(rdram, ctx);
        goto after_12;
    // 0x80102DD8: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_12:
    // 0x80102DDC: jal         0x800C76B0
    // 0x80102DE0: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    activateObjectiveCompleteFlag(rdram, ctx);
        goto after_13;
    // 0x80102DE0: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_13:
    // 0x80102DE4: jal         0x800C76B0
    // 0x80102DE8: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    activateObjectiveCompleteFlag(rdram, ctx);
        goto after_14;
    // 0x80102DE8: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    after_14:
    // 0x80102DEC: jal         0x800C776C
    // 0x80102DF0: nop

    setHudEnableBit8(rdram, ctx);
        goto after_15;
    // 0x80102DF0: nop

    after_15:
    // 0x80102DF4: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // 0x80102DF8: jal         0x800C7D1C
    // 0x80102DFC: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    playObjectiveVoiceLine2(rdram, ctx);
        goto after_16;
    // 0x80102DFC: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_16:
L_80102E00:
    // 0x80102E00: jal         0x800C759C
    // 0x80102E04: addiu       $a0, $zero, 0x15
    ctx->r4 = ADD32(0, 0X15);
    getObjectiveBoolean(rdram, ctx);
        goto after_17;
    // 0x80102E04: addiu       $a0, $zero, 0x15
    ctx->r4 = ADD32(0, 0X15);
    after_17:
    // 0x80102E08: blez        $v0, L_80102E3C
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80102E0C: lui         $v1, 0x8011
        ctx->r3 = S32(0X8011 << 16);
            goto L_80102E3C;
    }
    // 0x80102E0C: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x80102E10: lw          $v0, -0x2FB0($v1)
    ctx->r2 = MEM_W(ctx->r3, -0X2FB0);
    // 0x80102E14: bne         $v0, $zero, L_80102E3C
    if (ctx->r2 != 0) {
        // 0x80102E18: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80102E3C;
    }
    // 0x80102E18: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80102E1C: jal         0x800C7738
    // 0x80102E20: sw          $v0, -0x2FB0($v1)
    MEM_W(-0X2FB0, ctx->r3) = ctx->r2;
    setHudEnableBit4(rdram, ctx);
        goto after_18;
    // 0x80102E20: sw          $v0, -0x2FB0($v1)
    MEM_W(-0X2FB0, ctx->r3) = ctx->r2;
    after_18:
    // 0x80102E24: addiu       $a0, $zero, 0x56
    ctx->r4 = ADD32(0, 0X56);
    // 0x80102E28: jal         0x800C7D1C
    // 0x80102E2C: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    playObjectiveVoiceLine2(rdram, ctx);
        goto after_19;
    // 0x80102E2C: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_19:
    // 0x80102E30: lui         $a1, 0x3F00
    ctx->r5 = S32(0X3F00 << 16);
    // 0x80102E34: jal         0x800C7D1C
    // 0x80102E38: addiu       $a0, $zero, 0x5D
    ctx->r4 = ADD32(0, 0X5D);
    playObjectiveVoiceLine2(rdram, ctx);
        goto after_20;
    // 0x80102E38: addiu       $a0, $zero, 0x5D
    ctx->r4 = ADD32(0, 0X5D);
    after_20:
L_80102E3C:
    // 0x80102E3C: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80102E40: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x80102E44: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x80102E48: jr          $ra
    // 0x80102E4C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80102E4C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void lv3_startMissionAndBriefing(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80102E50: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80102E54: addiu       $a0, $zero, 0xB
    ctx->r4 = ADD32(0, 0XB);
    // 0x80102E58: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80102E5C: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x80102E60: jal         0x800C7540
    // 0x80102E64: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    setObjectiveBoolean(rdram, ctx);
        goto after_0;
    // 0x80102E64: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x80102E68: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
    // 0x80102E6C: jal         0x800C7540
    // 0x80102E70: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    setObjectiveBoolean(rdram, ctx);
        goto after_1;
    // 0x80102E70: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x80102E74: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x80102E78: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x80102E7C: jal         0x800C7884
    // 0x80102E80: addiu       $a0, $a0, -0x6990
    ctx->r4 = ADD32(ctx->r4, -0X6990);
    setHudFlagBit40AndStoreArg(rdram, ctx);
        goto after_2;
    // 0x80102E80: addiu       $a0, $a0, -0x6990
    ctx->r4 = ADD32(ctx->r4, -0X6990);
    after_2:
    // 0x80102E84: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80102E88: jal         0x800C7D1C
    // 0x80102E8C: addiu       $a0, $zero, 0x1E8
    ctx->r4 = ADD32(0, 0X1E8);
    playObjectiveVoiceLine2(rdram, ctx);
        goto after_3;
    // 0x80102E8C: addiu       $a0, $zero, 0x1E8
    ctx->r4 = ADD32(0, 0X1E8);
    after_3:
    // 0x80102E90: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80102E94: jal         0x800C7D1C
    // 0x80102E98: addiu       $a0, $zero, 0x1E6
    ctx->r4 = ADD32(0, 0X1E6);
    playObjectiveVoiceLine2(rdram, ctx);
        goto after_4;
    // 0x80102E98: addiu       $a0, $zero, 0x1E6
    ctx->r4 = ADD32(0, 0X1E6);
    after_4:
    // 0x80102E9C: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80102EA0: jal         0x800C7D1C
    // 0x80102EA4: addiu       $a0, $zero, 0x156
    ctx->r4 = ADD32(0, 0X156);
    playObjectiveVoiceLine2(rdram, ctx);
        goto after_5;
    // 0x80102EA4: addiu       $a0, $zero, 0x156
    ctx->r4 = ADD32(0, 0X156);
    after_5:
    // 0x80102EA8: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    // 0x80102EAC: jal         0x800C7D1C
    // 0x80102EB0: addiu       $a0, $zero, 0x8D
    ctx->r4 = ADD32(0, 0X8D);
    playObjectiveVoiceLine2(rdram, ctx);
        goto after_6;
    // 0x80102EB0: addiu       $a0, $zero, 0x8D
    ctx->r4 = ADD32(0, 0X8D);
    after_6:
    // 0x80102EB4: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80102EB8: jal         0x800C7D1C
    // 0x80102EBC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    playObjectiveVoiceLine2(rdram, ctx);
        goto after_7;
    // 0x80102EBC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_7:
    // 0x80102EC0: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80102EC4: jal         0x800C7D1C
    // 0x80102EC8: addiu       $a0, $zero, 0x13D
    ctx->r4 = ADD32(0, 0X13D);
    playObjectiveVoiceLine2(rdram, ctx);
        goto after_8;
    // 0x80102EC8: addiu       $a0, $zero, 0x13D
    ctx->r4 = ADD32(0, 0X13D);
    after_8:
    // 0x80102ECC: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80102ED0: jal         0x800C7D1C
    // 0x80102ED4: addiu       $a0, $zero, 0x8E
    ctx->r4 = ADD32(0, 0X8E);
    playObjectiveVoiceLine2(rdram, ctx);
        goto after_9;
    // 0x80102ED4: addiu       $a0, $zero, 0x8E
    ctx->r4 = ADD32(0, 0X8E);
    after_9:
    // 0x80102ED8: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x80102EDC: lui         $a1, 0x4170
    ctx->r5 = S32(0X4170 << 16);
    // 0x80102EE0: jal         0x800C7864
    // 0x80102EE4: addiu       $a0, $a0, 0x3268
    ctx->r4 = ADD32(ctx->r4, 0X3268);
    addTimerHandleWrapper(rdram, ctx);
        goto after_10;
    // 0x80102EE4: addiu       $a0, $a0, 0x3268
    ctx->r4 = ADD32(ctx->r4, 0X3268);
    after_10:
    // 0x80102EE8: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x80102EEC: lui         $a1, 0x4180
    ctx->r5 = S32(0X4180 << 16);
    // 0x80102EF0: jal         0x800C7864
    // 0x80102EF4: addiu       $a0, $a0, 0x3248
    ctx->r4 = ADD32(ctx->r4, 0X3248);
    addTimerHandleWrapper(rdram, ctx);
        goto after_11;
    // 0x80102EF4: addiu       $a0, $a0, 0x3248
    ctx->r4 = ADD32(ctx->r4, 0X3248);
    after_11:
    // 0x80102EF8: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x80102EFC: lui         $a1, 0x41A0
    ctx->r5 = S32(0X41A0 << 16);
    // 0x80102F00: jal         0x800C7864
    // 0x80102F04: addiu       $a0, $a0, 0x3444
    ctx->r4 = ADD32(ctx->r4, 0X3444);
    addTimerHandleWrapper(rdram, ctx);
        goto after_12;
    // 0x80102F04: addiu       $a0, $a0, 0x3444
    ctx->r4 = ADD32(ctx->r4, 0X3444);
    after_12:
    // 0x80102F08: addiu       $a0, $zero, 0x6F
    ctx->r4 = ADD32(0, 0X6F);
    // 0x80102F0C: jal         0x800C7540
    // 0x80102F10: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    setObjectiveBoolean(rdram, ctx);
        goto after_13;
    // 0x80102F10: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_13:
    // 0x80102F14: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x80102F18: lui         $a1, 0x40C0
    ctx->r5 = S32(0X40C0 << 16);
    // 0x80102F1C: jal         0x800C7864
    // 0x80102F20: addiu       $a0, $a0, 0x322C
    ctx->r4 = ADD32(ctx->r4, 0X322C);
    addTimerHandleWrapper(rdram, ctx);
        goto after_14;
    // 0x80102F20: addiu       $a0, $a0, 0x322C
    ctx->r4 = ADD32(ctx->r4, 0X322C);
    after_14:
    // 0x80102F24: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80102F28: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x80102F2C: jr          $ra
    // 0x80102F30: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80102F30: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void scheduleLv3TriggerProgressA_3s(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80102F34: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80102F38: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x80102F3C: lui         $a1, 0x4040
    ctx->r5 = S32(0X4040 << 16);
    // 0x80102F40: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80102F44: jal         0x800C7864
    // 0x80102F48: addiu       $a0, $a0, 0x2F58
    ctx->r4 = ADD32(ctx->r4, 0X2F58);
    addTimerHandleWrapper(rdram, ctx);
        goto after_0;
    // 0x80102F48: addiu       $a0, $a0, 0x2F58
    ctx->r4 = ADD32(ctx->r4, 0X2F58);
    after_0:
    // 0x80102F4C: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80102F50: jr          $ra
    // 0x80102F54: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80102F54: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void lv3_triggerObjectiveProgressA(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80102F58: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80102F5C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80102F60: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80102F64: jal         0x800C75EC
    // 0x80102F68: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    increaseObjectiveCount(rdram, ctx);
        goto after_0;
    // 0x80102F68: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    after_0:
    // 0x80102F6C: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    // 0x80102F70: jal         0x800C7540
    // 0x80102F74: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    setObjectiveBoolean(rdram, ctx);
        goto after_1;
    // 0x80102F74: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x80102F78: addiu       $a0, $zero, 0x27
    ctx->r4 = ADD32(0, 0X27);
    // 0x80102F7C: jal         0x800C7540
    // 0x80102F80: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    setObjectiveBoolean(rdram, ctx);
        goto after_2;
    // 0x80102F80: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
    // 0x80102F84: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x80102F88: jal         0x800C7884
    // 0x80102F8C: addiu       $a0, $a0, -0x69AC
    ctx->r4 = ADD32(ctx->r4, -0X69AC);
    setHudFlagBit40AndStoreArg(rdram, ctx);
        goto after_3;
    // 0x80102F8C: addiu       $a0, $a0, -0x69AC
    ctx->r4 = ADD32(ctx->r4, -0X69AC);
    after_3:
    // 0x80102F90: lui         $a1, 0x3F00
    ctx->r5 = S32(0X3F00 << 16);
    // 0x80102F94: jal         0x800C7D1C
    // 0x80102F98: addiu       $a0, $zero, 0x5A
    ctx->r4 = ADD32(0, 0X5A);
    playObjectiveVoiceLine2(rdram, ctx);
        goto after_4;
    // 0x80102F98: addiu       $a0, $zero, 0x5A
    ctx->r4 = ADD32(0, 0X5A);
    after_4:
    // 0x80102F9C: addiu       $a0, $zero, 0x235
    ctx->r4 = ADD32(0, 0X235);
    // 0x80102FA0: jal         0x800C7D1C
    // 0x80102FA4: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    playObjectiveVoiceLine2(rdram, ctx);
        goto after_5;
    // 0x80102FA4: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_5:
    // 0x80102FA8: addiu       $a0, $zero, 0xD
    ctx->r4 = ADD32(0, 0XD);
    // 0x80102FAC: jal         0x800C75EC
    // 0x80102FB0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    increaseObjectiveCount(rdram, ctx);
        goto after_6;
    // 0x80102FB0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_6:
    // 0x80102FB4: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x80102FB8: lui         $a1, 0x4000
    ctx->r5 = S32(0X4000 << 16);
    // 0x80102FBC: jal         0x800C7864
    // 0x80102FC0: addiu       $a0, $a0, 0x2FF0
    ctx->r4 = ADD32(ctx->r4, 0X2FF0);
    addTimerHandleWrapper(rdram, ctx);
        goto after_7;
    // 0x80102FC0: addiu       $a0, $a0, 0x2FF0
    ctx->r4 = ADD32(ctx->r4, 0X2FF0);
    after_7:
    // 0x80102FC4: jal         0x800C76B0
    // 0x80102FC8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    activateObjectiveCompleteFlag(rdram, ctx);
        goto after_8;
    // 0x80102FC8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_8:
    // 0x80102FCC: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x80102FD0: jal         0x800C7660
    // 0x80102FD4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    setObjectiveHiddenFlag(rdram, ctx);
        goto after_9;
    // 0x80102FD4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_9:
    // 0x80102FD8: addiu       $a0, $zero, 0x6E
    ctx->r4 = ADD32(0, 0X6E);
    // 0x80102FDC: jal         0x800C7540
    // 0x80102FE0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    setObjectiveBoolean(rdram, ctx);
        goto after_10;
    // 0x80102FE0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_10:
    // 0x80102FE4: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80102FE8: jr          $ra
    // 0x80102FEC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80102FEC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void lv3_clearBoolean_0x6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80102FF0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80102FF4: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    // 0x80102FF8: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80102FFC: jal         0x800C7540
    // 0x80103000: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    setObjectiveBoolean(rdram, ctx);
        goto after_0;
    // 0x80103000: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_0:
    // 0x80103004: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80103008: jr          $ra
    // 0x8010300C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8010300C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void lv3_dialogueAndStateWithTimer(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80103010: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80103014: addiu       $a0, $zero, 0x101
    ctx->r4 = ADD32(0, 0X101);
    // 0x80103018: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x8010301C: jal         0x800C7D1C
    // 0x80103020: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    playObjectiveVoiceLine2(rdram, ctx);
        goto after_0;
    // 0x80103020: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_0:
    // 0x80103024: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x80103028: lui         $a1, 0x40C0
    ctx->r5 = S32(0X40C0 << 16);
    // 0x8010302C: jal         0x800C7864
    // 0x80103030: addiu       $a0, $a0, 0x304C
    ctx->r4 = ADD32(ctx->r4, 0X304C);
    addTimerHandleWrapper(rdram, ctx);
        goto after_1;
    // 0x80103030: addiu       $a0, $a0, 0x304C
    ctx->r4 = ADD32(ctx->r4, 0X304C);
    after_1:
    // 0x80103034: addiu       $a0, $zero, 0x21
    ctx->r4 = ADD32(0, 0X21);
    // 0x80103038: jal         0x800C7540
    // 0x8010303C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    setObjectiveBoolean(rdram, ctx);
        goto after_2;
    // 0x8010303C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
    // 0x80103040: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80103044: jr          $ra
    // 0x80103048: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80103048: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void lv3_runDialogueSequenceA(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010304C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80103050: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x80103054: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x80103058: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x8010305C: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80103060: jal         0x800C7660
    // 0x80103064: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    setObjectiveHiddenFlag(rdram, ctx);
        goto after_0;
    // 0x80103064: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x80103068: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x8010306C: jal         0x800C7D1C
    // 0x80103070: addiu       $a0, $zero, 0x28D
    ctx->r4 = ADD32(0, 0X28D);
    playObjectiveVoiceLine2(rdram, ctx);
        goto after_1;
    // 0x80103070: addiu       $a0, $zero, 0x28D
    ctx->r4 = ADD32(0, 0X28D);
    after_1:
    // 0x80103074: lui         $a1, 0x3E4C
    ctx->r5 = S32(0X3E4C << 16);
    // 0x80103078: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x8010307C: jal         0x800C7D1C
    // 0x80103080: addiu       $a0, $zero, 0x11A
    ctx->r4 = ADD32(0, 0X11A);
    playObjectiveVoiceLine2(rdram, ctx);
        goto after_2;
    // 0x80103080: addiu       $a0, $zero, 0x11A
    ctx->r4 = ADD32(0, 0X11A);
    after_2:
    // 0x80103084: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80103088: jal         0x800C7D1C
    // 0x8010308C: addiu       $a0, $zero, 0x103
    ctx->r4 = ADD32(0, 0X103);
    playObjectiveVoiceLine2(rdram, ctx);
        goto after_3;
    // 0x8010308C: addiu       $a0, $zero, 0x103
    ctx->r4 = ADD32(0, 0X103);
    after_3:
    // 0x80103090: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80103094: jal         0x800C7D1C
    // 0x80103098: addiu       $a0, $zero, 0x1EF
    ctx->r4 = ADD32(0, 0X1EF);
    playObjectiveVoiceLine2(rdram, ctx);
        goto after_4;
    // 0x80103098: addiu       $a0, $zero, 0x1EF
    ctx->r4 = ADD32(0, 0X1EF);
    after_4:
    // 0x8010309C: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
    // 0x801030A0: jal         0x800C75EC
    // 0x801030A4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    increaseObjectiveCount(rdram, ctx);
        goto after_5;
    // 0x801030A4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_5:
    // 0x801030A8: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x801030AC: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x801030B0: jr          $ra
    // 0x801030B4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x801030B4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void lv3_playPairedDialogueA(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801030B8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801030BC: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x801030C0: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x801030C4: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x801030C8: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x801030CC: jal         0x800C7D1C
    // 0x801030D0: addiu       $a0, $zero, 0x275
    ctx->r4 = ADD32(0, 0X275);
    playObjectiveVoiceLine2(rdram, ctx);
        goto after_0;
    // 0x801030D0: addiu       $a0, $zero, 0x275
    ctx->r4 = ADD32(0, 0X275);
    after_0:
    // 0x801030D4: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x801030D8: jal         0x800C7D1C
    // 0x801030DC: addiu       $a0, $zero, 0x234
    ctx->r4 = ADD32(0, 0X234);
    playObjectiveVoiceLine2(rdram, ctx);
        goto after_1;
    // 0x801030DC: addiu       $a0, $zero, 0x234
    ctx->r4 = ADD32(0, 0X234);
    after_1:
    // 0x801030E0: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x801030E4: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x801030E8: jr          $ra
    // 0x801030EC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x801030EC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void playVoice2_0x233(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801030F0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801030F4: addiu       $a0, $zero, 0x233
    ctx->r4 = ADD32(0, 0X233);
    // 0x801030F8: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x801030FC: jal         0x800C7D1C
    // 0x80103100: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    playObjectiveVoiceLine2(rdram, ctx);
        goto after_0;
    // 0x80103100: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_0:
    // 0x80103104: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80103108: jr          $ra
    // 0x8010310C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8010310C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void playVoice2_0x13C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80103110: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80103114: addiu       $a0, $zero, 0x13C
    ctx->r4 = ADD32(0, 0X13C);
    // 0x80103118: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x8010311C: jal         0x800C7D1C
    // 0x80103120: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    playObjectiveVoiceLine2(rdram, ctx);
        goto after_0;
    // 0x80103120: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_0:
    // 0x80103124: lui         $a1, 0x4020
    ctx->r5 = S32(0X4020 << 16);
    // 0x80103128: jal         0x800C7D1C
    // 0x8010312C: addiu       $a0, $zero, 0x5B
    ctx->r4 = ADD32(0, 0X5B);
    playObjectiveVoiceLine2(rdram, ctx);
        goto after_1;
    // 0x8010312C: addiu       $a0, $zero, 0x5B
    ctx->r4 = ADD32(0, 0X5B);
    after_1:
    // 0x80103130: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80103134: jr          $ra
    // 0x80103138: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80103138: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void scheduleLv3ObjectiveTimers_3s(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010313C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80103140: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x80103144: lui         $a1, 0x4040
    ctx->r5 = S32(0X4040 << 16);
    // 0x80103148: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x8010314C: jal         0x800C7864
    // 0x80103150: addiu       $a0, $a0, 0x3160
    ctx->r4 = ADD32(ctx->r4, 0X3160);
    addTimerHandleWrapper(rdram, ctx);
        goto after_0;
    // 0x80103150: addiu       $a0, $a0, 0x3160
    ctx->r4 = ADD32(ctx->r4, 0X3160);
    after_0:
    // 0x80103154: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80103158: jr          $ra
    // 0x8010315C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8010315C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void lv3_scheduleObjectiveTimers(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80103160: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80103164: lui         $a1, 0x40A0
    ctx->r5 = S32(0X40A0 << 16);
    // 0x80103168: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x8010316C: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x80103170: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80103174: lwc1        $f20, -0x6948($at)
    ctx->f20.u32l = MEM_W(ctx->r1, -0X6948);
    // 0x80103178: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x8010317C: jal         0x800C7864
    // 0x80103180: addiu       $a0, $a0, 0x31C4
    ctx->r4 = ADD32(ctx->r4, 0X31C4);
    addTimerHandleWrapper(rdram, ctx);
        goto after_0;
    // 0x80103180: addiu       $a0, $a0, 0x31C4
    ctx->r4 = ADD32(ctx->r4, 0X31C4);
    after_0:
    // 0x80103184: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80103188: jal         0x800C7D1C
    // 0x8010318C: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    playObjectiveVoiceLine2(rdram, ctx);
        goto after_1;
    // 0x8010318C: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    after_1:
    // 0x80103190: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80103194: jal         0x800C7D1C
    // 0x80103198: addiu       $a0, $zero, 0x236
    ctx->r4 = ADD32(0, 0X236);
    playObjectiveVoiceLine2(rdram, ctx);
        goto after_2;
    // 0x80103198: addiu       $a0, $zero, 0x236
    ctx->r4 = ADD32(0, 0X236);
    after_2:
    // 0x8010319C: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x801031A0: jal         0x800C7660
    // 0x801031A4: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    setObjectiveHiddenFlag(rdram, ctx);
        goto after_3;
    // 0x801031A4: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_3:
    // 0x801031A8: addiu       $a0, $zero, 0x28
    ctx->r4 = ADD32(0, 0X28);
    // 0x801031AC: jal         0x800C7540
    // 0x801031B0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    setObjectiveBoolean(rdram, ctx);
        goto after_4;
    // 0x801031B0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_4:
    // 0x801031B4: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x801031B8: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x801031BC: jr          $ra
    // 0x801031C0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x801031C0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void lv3_updateHudAndProgress(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801031C4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801031C8: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x801031CC: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x801031D0: jal         0x800C7884
    // 0x801031D4: addiu       $a0, $a0, -0x699C
    ctx->r4 = ADD32(ctx->r4, -0X699C);
    setHudFlagBit40AndStoreArg(rdram, ctx);
        goto after_0;
    // 0x801031D4: addiu       $a0, $a0, -0x699C
    ctx->r4 = ADD32(ctx->r4, -0X699C);
    after_0:
    // 0x801031D8: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    // 0x801031DC: jal         0x800C75EC
    // 0x801031E0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    increaseObjectiveCount(rdram, ctx);
        goto after_1;
    // 0x801031E0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x801031E4: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    // 0x801031E8: jal         0x800C7540
    // 0x801031EC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    setObjectiveBoolean(rdram, ctx);
        goto after_2;
    // 0x801031EC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
    // 0x801031F0: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x801031F4: lui         $a1, 0x4100
    ctx->r5 = S32(0X4100 << 16);
    // 0x801031F8: jal         0x800C7864
    // 0x801031FC: addiu       $a0, $a0, 0x3288
    ctx->r4 = ADD32(ctx->r4, 0X3288);
    addTimerHandleWrapper(rdram, ctx);
        goto after_3;
    // 0x801031FC: addiu       $a0, $a0, 0x3288
    ctx->r4 = ADD32(ctx->r4, 0X3288);
    after_3:
    // 0x80103200: addiu       $a0, $zero, 0x6E
    ctx->r4 = ADD32(0, 0X6E);
    // 0x80103204: jal         0x800C7540
    // 0x80103208: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    setObjectiveBoolean(rdram, ctx);
        goto after_4;
    // 0x80103208: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_4:
    // 0x8010320C: addiu       $a0, $zero, 0x6F
    ctx->r4 = ADD32(0, 0X6F);
    // 0x80103210: jal         0x800C7540
    // 0x80103214: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    setObjectiveBoolean(rdram, ctx);
        goto after_5;
    // 0x80103214: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_5:
    // 0x80103218: jal         0x800C7D98
    // 0x8010321C: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    triggerSoundCueByType(rdram, ctx);
        goto after_6;
    // 0x8010321C: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_6:
    // 0x80103220: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80103224: jr          $ra
    // 0x80103228: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80103228: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void triggerSoundCue5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010322C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80103230: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80103234: jal         0x800C7D98
    // 0x80103238: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    triggerSoundCueByType(rdram, ctx);
        goto after_0;
    // 0x80103238: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    after_0:
    // 0x8010323C: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80103240: jr          $ra
    // 0x80103244: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80103244: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void setObjBoolTrue_0x1F(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80103248: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8010324C: addiu       $a0, $zero, 0x1F
    ctx->r4 = ADD32(0, 0X1F);
    // 0x80103250: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80103254: jal         0x800C7540
    // 0x80103258: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    setObjectiveBoolean(rdram, ctx);
        goto after_0;
    // 0x80103258: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x8010325C: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80103260: jr          $ra
    // 0x80103264: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80103264: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void lv3_setBoolean_0x10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80103268: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8010326C: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    // 0x80103270: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80103274: jal         0x800C7540
    // 0x80103278: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    setObjectiveBoolean(rdram, ctx);
        goto after_0;
    // 0x80103278: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x8010327C: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80103280: jr          $ra
    // 0x80103284: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80103284: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void lv3_setDoubleBoolean(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80103288: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8010328C: addiu       $a0, $zero, 0x9
    ctx->r4 = ADD32(0, 0X9);
    // 0x80103290: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80103294: jal         0x800C7540
    // 0x80103298: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    setObjectiveBoolean(rdram, ctx);
        goto after_0;
    // 0x80103298: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x8010329C: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    // 0x801032A0: jal         0x800C7540
    // 0x801032A4: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    setObjectiveBoolean(rdram, ctx);
        goto after_1;
    // 0x801032A4: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_1:
    // 0x801032A8: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x801032AC: jr          $ra
    // 0x801032B0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x801032B0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void lv3_progressWithDialogueA(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801032B4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801032B8: addiu       $a0, $zero, 0x5C
    ctx->r4 = ADD32(0, 0X5C);
    // 0x801032BC: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x801032C0: jal         0x800C7D1C
    // 0x801032C4: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    playObjectiveVoiceLine2(rdram, ctx);
        goto after_0;
    // 0x801032C4: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_0:
    // 0x801032C8: addiu       $a0, $zero, 0x11
    ctx->r4 = ADD32(0, 0X11);
    // 0x801032CC: jal         0x800C75EC
    // 0x801032D0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    increaseObjectiveCount(rdram, ctx);
        goto after_1;
    // 0x801032D0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x801032D4: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x801032D8: lui         $a1, 0x40A0
    ctx->r5 = S32(0X40A0 << 16);
    // 0x801032DC: jal         0x800C7864
    // 0x801032E0: addiu       $a0, $a0, 0x2E50
    ctx->r4 = ADD32(ctx->r4, 0X2E50);
    addTimerHandleWrapper(rdram, ctx);
        goto after_2;
    // 0x801032E0: addiu       $a0, $a0, 0x2E50
    ctx->r4 = ADD32(ctx->r4, 0X2E50);
    after_2:
    // 0x801032E4: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x801032E8: jr          $ra
    // 0x801032EC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x801032EC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void lv3_playPairedDialogueB(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801032F0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801032F4: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x801032F8: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x801032FC: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80103300: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80103304: jal         0x800C7D1C
    // 0x80103308: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    playObjectiveVoiceLine2(rdram, ctx);
        goto after_0;
    // 0x80103308: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_0:
    // 0x8010330C: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80103310: jal         0x800C7D1C
    // 0x80103314: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    playObjectiveVoiceLine2(rdram, ctx);
        goto after_1;
    // 0x80103314: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_1:
    // 0x80103318: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x8010331C: jal         0x800C7D1C
    // 0x80103320: addiu       $a0, $zero, 0x8F
    ctx->r4 = ADD32(0, 0X8F);
    playObjectiveVoiceLine2(rdram, ctx);
        goto after_2;
    // 0x80103320: addiu       $a0, $zero, 0x8F
    ctx->r4 = ADD32(0, 0X8F);
    after_2:
    // 0x80103324: addiu       $a0, $zero, 0x14
    ctx->r4 = ADD32(0, 0X14);
    // 0x80103328: jal         0x800C75EC
    // 0x8010332C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    increaseObjectiveCount(rdram, ctx);
        goto after_3;
    // 0x8010332C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_3:
    // 0x80103330: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80103334: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x80103338: jr          $ra
    // 0x8010333C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x8010333C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void lv3_setBoolean_0x11(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80103340: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80103344: addiu       $a0, $zero, 0x11
    ctx->r4 = ADD32(0, 0X11);
    // 0x80103348: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x8010334C: jal         0x800C7540
    // 0x80103350: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    setObjectiveBoolean(rdram, ctx);
        goto after_0;
    // 0x80103350: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x80103354: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80103358: jr          $ra
    // 0x8010335C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8010335C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void scheduleLv3SetStateBooleans_3s(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80103360: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80103364: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x80103368: lui         $a1, 0x4040
    ctx->r5 = S32(0X4040 << 16);
    // 0x8010336C: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80103370: jal         0x800C7864
    // 0x80103374: addiu       $a0, $a0, 0x3384
    ctx->r4 = ADD32(ctx->r4, 0X3384);
    addTimerHandleWrapper(rdram, ctx);
        goto after_0;
    // 0x80103374: addiu       $a0, $a0, 0x3384
    ctx->r4 = ADD32(ctx->r4, 0X3384);
    after_0:
    // 0x80103378: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x8010337C: jr          $ra
    // 0x80103380: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80103380: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void lv3_setMissionStateBooleans(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80103384: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80103388: addiu       $a0, $zero, 0x13
    ctx->r4 = ADD32(0, 0X13);
    // 0x8010338C: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80103390: jal         0x800C7540
    // 0x80103394: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    setObjectiveBoolean(rdram, ctx);
        goto after_0;
    // 0x80103394: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x80103398: addiu       $a0, $zero, 0x14
    ctx->r4 = ADD32(0, 0X14);
    // 0x8010339C: jal         0x800C7540
    // 0x801033A0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    setObjectiveBoolean(rdram, ctx);
        goto after_1;
    // 0x801033A0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x801033A4: addiu       $a0, $zero, 0x17
    ctx->r4 = ADD32(0, 0X17);
    // 0x801033A8: jal         0x800C75EC
    // 0x801033AC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    increaseObjectiveCount(rdram, ctx);
        goto after_2;
    // 0x801033AC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
    // 0x801033B0: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x801033B4: jal         0x800C7884
    // 0x801033B8: addiu       $a0, $a0, -0x6980
    ctx->r4 = ADD32(ctx->r4, -0X6980);
    setHudFlagBit40AndStoreArg(rdram, ctx);
        goto after_3;
    // 0x801033B8: addiu       $a0, $a0, -0x6980
    ctx->r4 = ADD32(ctx->r4, -0X6980);
    after_3:
    // 0x801033BC: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    // 0x801033C0: jal         0x800C7D1C
    // 0x801033C4: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    playObjectiveVoiceLine2(rdram, ctx);
        goto after_4;
    // 0x801033C4: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_4:
    // 0x801033C8: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    // 0x801033CC: jal         0x800C75EC
    // 0x801033D0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    increaseObjectiveCount(rdram, ctx);
        goto after_5;
    // 0x801033D0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_5:
    // 0x801033D4: addiu       $a0, $zero, 0x6F
    ctx->r4 = ADD32(0, 0X6F);
    // 0x801033D8: jal         0x800C7540
    // 0x801033DC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    setObjectiveBoolean(rdram, ctx);
        goto after_6;
    // 0x801033DC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_6:
    // 0x801033E0: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x801033E4: jr          $ra
    // 0x801033E8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x801033E8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void lv3_progressWithDialogueB(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801033EC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801033F0: addiu       $a0, $zero, 0x18
    ctx->r4 = ADD32(0, 0X18);
    // 0x801033F4: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x801033F8: jal         0x800C75EC
    // 0x801033FC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    increaseObjectiveCount(rdram, ctx);
        goto after_0;
    // 0x801033FC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x80103400: addiu       $a0, $zero, 0x29E
    ctx->r4 = ADD32(0, 0X29E);
    // 0x80103404: jal         0x800C7D1C
    // 0x80103408: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    playObjectiveVoiceLine2(rdram, ctx);
        goto after_1;
    // 0x80103408: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_1:
    // 0x8010340C: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x80103410: jal         0x800C7660
    // 0x80103414: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    setObjectiveHiddenFlag(rdram, ctx);
        goto after_2;
    // 0x80103414: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_2:
    // 0x80103418: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x8010341C: jr          $ra
    // 0x80103420: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80103420: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void playVoice2_0x2F3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80103424: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80103428: lui         $a1, 0x4000
    ctx->r5 = S32(0X4000 << 16);
    // 0x8010342C: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80103430: jal         0x800C7D1C
    // 0x80103434: addiu       $a0, $zero, 0x2F3
    ctx->r4 = ADD32(0, 0X2F3);
    playObjectiveVoiceLine2(rdram, ctx);
        goto after_0;
    // 0x80103434: addiu       $a0, $zero, 0x2F3
    ctx->r4 = ADD32(0, 0X2F3);
    after_0:
    // 0x80103438: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x8010343C: jr          $ra
    // 0x80103440: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80103440: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void playVoice2_0x29F(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80103444: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80103448: addiu       $a0, $zero, 0x29F
    ctx->r4 = ADD32(0, 0X29F);
    // 0x8010344C: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80103450: jal         0x800C7D1C
    // 0x80103454: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    playObjectiveVoiceLine2(rdram, ctx);
        goto after_0;
    // 0x80103454: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_0:
    // 0x80103458: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x8010345C: jr          $ra
    // 0x80103460: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80103460: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void playVoice2_0x126(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80103464: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80103468: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x8010346C: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x80103470: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80103474: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80103478: jal         0x800C7D1C
    // 0x8010347C: addiu       $a0, $zero, 0x126
    ctx->r4 = ADD32(0, 0X126);
    playObjectiveVoiceLine2(rdram, ctx);
        goto after_0;
    // 0x8010347C: addiu       $a0, $zero, 0x126
    ctx->r4 = ADD32(0, 0X126);
    after_0:
    // 0x80103480: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80103484: jal         0x800C7D1C
    // 0x80103488: addiu       $a0, $zero, 0x127
    ctx->r4 = ADD32(0, 0X127);
    playObjectiveVoiceLine2(rdram, ctx);
        goto after_1;
    // 0x80103488: addiu       $a0, $zero, 0x127
    ctx->r4 = ADD32(0, 0X127);
    after_1:
    // 0x8010348C: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80103490: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x80103494: jr          $ra
    // 0x80103498: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80103498: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
