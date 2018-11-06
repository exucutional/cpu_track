/*!
 * \brief cmd_list.h
 * \author Exdev
 * \version 1.0.0
 * \brief Format : DEF_CMD(name, value)
 * value = 1 -> next act = get cmd
 * value = 2 -> next act = get reg
 * value = 3 -> next act = get number
 * value = 4 -> next act = get label
 */


DEF_CMD(nop, 1)
DEF_CMD(syscall, 1)
// DEF_CMD(pushmr, 1)
DEF_CMD(pushq, 3)
// DEF_CMD(pushr, 2)
// DEF_CMD(pushm, 1)
// DEF_CMD(popmr, 1)
// DEF_CMD(popr, 2)
// DEF_CMD(popm, 1)
// DEF_CMD(add, 1)
// DEF_CMD(sub, 1)
// DEF_CMD(mul, 1)
// DEF_CMD(div, 1)
// DEF_CMD(jmp, 4)
