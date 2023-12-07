#pragma once
#include <QString>
#include "Components_global.h"

namespace StyleSheets{
const QString FlowItemChecked =
    "QFrame#frame                                \
    {                                            \
        border-color: rgb(85, 255, 127);         \
        background-color: rgb(85, 65, 255);      \
    }";

const QString FlowItemUnChecked =
    "QFrame#frame                                \
{                                                \
        border-color: rgb(149, 149, 149);        \
        background-color: rgb(85, 170, 127);     \
}";

const QString FlowItemLoseQC_UnChecked =
    "QFrame#frame                                \
{                                                \
        border-color: rgb(149, 149, 149);        \
        background-color: red;     \
}";

const QString FlowItemWaringQC_UnChecked =
    "QFrame#frame                                \
{                                                \
        border-color: rgb(149, 149, 149);        \
        background-color: orange;                \
}";

const QString FlowItemInQC_UnChecked =
    "QFrame#frame                                \
{                                                \
        border-color: rgb(149, 149, 149);        \
        background-color: blue;                 \
}";

const QString FlowItemUnQC_UnChecked =
    "QFrame#frame                                \
{                                                \
        border-color: rgb(149, 149, 149);        \
        background-color: gray;                 \
}";

/*******************************************************************************/
const QString FlowItemLoseQC_Checked =
    "QFrame#frame                                \
{                                                \
        border: 5px solid black;                 \
        border-color: rgb(149, 149, 149);        \
        background-color: red;     \
}";

    const QString FlowItemWaringQC_Checked =
    "QFrame#frame                                \
{                                                \
        border: 5px solid black;                 \
        border-color: rgb(149, 149, 149);        \
        background-color: orange;                \
}";

    const QString FlowItemInQC_Checked =
    "QFrame#frame                                \
{                                                \
        border: 5px solid black;                 \
        border-color: rgb(149, 149, 149);        \
        background-color: blue;                 \
}";

    const QString FlowItemUnQC_Checked =
    "QFrame#frame                                \
{                                                \
        border: 5px solid black;                 \
        border-color: rgb(149, 149, 149);        \
        background-color: gray;                 \
}";

}
