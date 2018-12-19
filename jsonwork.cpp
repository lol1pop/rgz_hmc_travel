#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QFile>
#include <QtDebug>


QJsonObject parseJson(){
    // QString val = R"_({"list":[{"categoryname":"одежда","stuff":[{"name":"футболка","status":"not_put"},{"name":"шорты","status":"not_put"},{"name":"джинсы","status":"not_put"},{"name":"кепка","status":"not_put"},{"name":"купальник","status":"not_put"}]},{"categoryname":"обувь","stuff":[{"name":"кроссовки","status":"not_put"}]}]})_";
     QString val;
      QFile file;
      file.setFileName("test.json");
      file.open(QIODevice::ReadOnly | QIODevice::Text);
      val = file.readAll();
      file.close();
      //qWarning() << val;
      QJsonDocument document = QJsonDocument::fromJson(val.toUtf8());
    return document.object();;
}

QJsonObject parseJson(QString val){
    // QString val = R"_({"list":[{"categoryname":"одежда","stuff":[{"name":"футболка","status":"not_put"},{"name":"шорты","status":"not_put"},{"name":"джинсы","status":"not_put"},{"name":"кепка","status":"not_put"},{"name":"купальник","status":"not_put"}]},{"categoryname":"обувь","stuff":[{"name":"кроссовки","status":"not_put"}]}]})_";
    QJsonDocument document = QJsonDocument::fromJson(val.toUtf8());
    return document.object();;
}

QJsonObject editJson(QString strJsonList, QString keyEdit, QString value){
    QJsonObject root ;
    root = parseJson(strJsonList);
    bool edit = false;
    QJsonValue jv = root["list"];
    QJsonArray ja = jv.toArray();
    for(int i = 0; i < ja.count(); i++){
        QJsonObject subtree = ja.at(i).toObject();
        for(auto key : subtree.keys() ){
            //key : status
            QJsonValue jvChild = subtree[key];
            if(jvChild.isArray()){
                QJsonArray jaChild = jvChild.toArray();
                for(int i = 0; i < jaChild.count(); i++){
                    QJsonObject subtreeChild = jaChild.at(i).toObject();
                    auto keyChild = subtreeChild.keys().at(0);
                    if(keyChild == keyEdit){
                        auto var = QJsonValue(value);
                        subtreeChild[keyChild] = var;
                        jaChild.removeAt(i);
                        jaChild.append(subtreeChild);
                        edit = true;
                        break;
                    }

                }
                if(edit)
                    subtree[key] = jaChild;
            }
        }
        if(edit){
            ja.removeAt(i);
            ja.append(subtree);
        }
    }
    if(edit)
        root["list"] = ja;
    qDebug()<<"key:"<< keyEdit <<" value:"<< value<<"\n JSON:: "<< root;
    return root;
}
