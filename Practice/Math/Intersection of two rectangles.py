def inter_area(s1, s2) -> int:
    bl_a_x, bl_a_y, tr_a_x, tr_a_y = s1[0], s1[1], s1[2], s1[3]
    bl_b_x, bl_b_y, tr_b_x, tr_b_y = s2[0], s2[1], s2[2], s2[3]

    return (
            (min(tr_a_x, tr_b_x) - max(bl_a_x, bl_b_x))
            * (min(tr_a_y, tr_b_y) - max(bl_a_y, bl_b_y))
    )