#include "spinboxdelegate.h"

#include "spinboxdelegate.h"

#include <QSpinBox>
#include <QComboBox>

//! [0]
SpinBoxDelegate::SpinBoxDelegate(QObject *parent)
    : QStyledItemDelegate(parent)
{
}
//! [0]

//! [1]
QWidget *SpinBoxDelegate::createEditor(QWidget *parent,
    const QStyleOptionViewItem &/* option */,
    const QModelIndex &index ) const
{
    if(index.column() == 1){
        QComboBox *box = new QComboBox(parent);
        QStringList str;
        for(int i(0); i < 4; i++){
            str << QString::number(i);
        }
        box->addItems(str);
        box->setFrame(false);
        return box;
    }
    QSpinBox *editor = new QSpinBox(parent);
    editor->setFrame(false);
    editor->setMinimum(0);
    editor->setMaximum(1000);

    return editor;
}
//! [1]

//! [2]
void SpinBoxDelegate::setEditorData(QWidget *editor,
                                    const QModelIndex &index) const
{
    int value = index.model()->data(index, Qt::EditRole).toInt();
    if(index.column() == 1){
        QComboBox *bo = static_cast<QComboBox*>(editor);
        bo->currentText().toInt();
    }
    else{
        QSpinBox *spinBox = static_cast<QSpinBox*>(editor);
        spinBox->setValue(value);
    }
}
//! [2]

//! [3]
void SpinBoxDelegate::setModelData(QWidget *editor, QAbstractItemModel *model,
                                   const QModelIndex &index) const
{
    if(index.column() == 1){
        QComboBox *box = static_cast<QComboBox*>(editor);
        box->currentText().toInt();
        int value = index.model()->data(index, Qt::EditRole).toInt();
        box->setCurrentText(QString::number(value));
        model->setData(index, value, Qt::EditRole);
    }
    else{
        QSpinBox *spinBox = static_cast<QSpinBox*>(editor);
        spinBox->interpretText();
        int value = spinBox->value();

        model->setData(index, value, Qt::EditRole);
    }
}
//! [3]

//! [4]
void SpinBoxDelegate::updateEditorGeometry(QWidget *editor,
    const QStyleOptionViewItem &option, const QModelIndex &/* index */) const
{
    editor->setGeometry(option.rect);
}
//! [4]



