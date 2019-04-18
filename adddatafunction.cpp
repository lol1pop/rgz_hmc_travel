#include "adddata.h"
#include "ui_adddata.h"
#include <QTreeWidgetItem>
#include <QMessageBox>
#include "treelisthandler.h"
#include "treejsonaddform.h"

void fillCboxCategories(Ui::AddData *_ui, QJsonObject root)
{
    _ui->insertBox->clear();
    QJsonValue jv = root.value("list");
    if(jv.isArray()){
        QJsonArray ja = jv.toArray();
        for(int i = 0; i < ja.count(); i++){
            QJsonObject subtree = ja.at(i).toObject();
            for(auto key : subtree.keys() ){
                _ui->insertBox->addItem(key);
            }
        }
    }
}

void initTreeView(Ui::AddData* _ui,QString val ){
   _ui->treeWidget->clear();
   _ui->treeWidget->setColumnCount(1);
   _ui->treeWidget->header()->resizeSection(0,200);
   _ui->treeWidget->header()->resizeSection(1,60);

   QJsonObject root ;

   if(val != ""){
       root = treeListHandler::parseJson(val);
   QList<QTreeWidgetItem *> listitems = TreeJsonAddForm::jsonInTreeView(root);
   _ui->treeWidget->addTopLevelItems(listitems);
   fillCboxCategories(_ui,root);
   }
}

