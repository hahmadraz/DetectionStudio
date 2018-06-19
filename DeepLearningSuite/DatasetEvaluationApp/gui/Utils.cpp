//
// Created by frivas on 19/02/17.
//

#include "Utils.h"

bool Utils::getListViewContent(const QListView *list, std::vector<std::string> &content, const std::string &prefix) {
    content.clear();

		if (list->model() == 0) {
			return false;
		}


    QModelIndexList selectedList =list->selectionModel()->selectedIndexes();
    for (auto it = selectedList.begin(), end = selectedList.end(); it != end; ++it){
        content.push_back(prefix + it->data().toString().toStdString());
    }

    return content.size() != 0;
}

bool Utils::getDeployerParamsContent(const QGroupBox* deployer_params, std::map<std::string, std::string>& deployer_params_map) {
    deployer_params_map.clear();

    if (!deployer_params->isEnabled())
        return false;


    QList<QLineEdit *> allLineEdits = deployer_params->findChildren<QLineEdit *>();

    QList<QLineEdit *>::iterator i;
    for (i = allLineEdits.begin(); i != allLineEdits.end(); ++i) {
        if ((*i)->text().toStdString().empty())
          throw std::invalid_argument("Please Enter All the Parameters");
    }
    /*foreach( QLineEdit* item, allLineEdits ) {
        std::cout << item->text().toStdString() << '\n';
    }*/

    deployer_params_map["Server"] = deployer_params->findChild<QRadioButton*>("radioButton_deployer_ros")->isChecked() ? "ROS" : "Ice";
    deployer_params_map["Proxy"] = deployer_params->findChild<QLineEdit*>("lineEdit_deployer_proxy")->text().toStdString();
    deployer_params_map["Format"] = deployer_params->findChild<QLineEdit*>("lineEdit_deployer_format")->text().toStdString();
    deployer_params_map["Topic"] = deployer_params->findChild<QLineEdit*>("lineEdit_deployer_topic")->text().toStdString();
    deployer_params_map["Name"] = deployer_params->findChild<QLineEdit*>("lineEdit_deployer_name")->text().toStdString();


    return true;

}

bool Utils::getInferencerParamsContent(const QGroupBox* inferencer_params, std::map<std::string, std::string>& inferencer_params_map) {
    inferencer_params_map.clear();

    if (!inferencer_params->isEnabled())
        return false;


    QList<QLineEdit *> allLineEdits = inferencer_params->findChildren<QLineEdit *>();

    QList<QLineEdit *>::iterator i;
    for (i = allLineEdits.begin(); i != allLineEdits.end(); ++i) {
        if ((*i)->text().toStdString().empty())
          throw std::invalid_argument("Please Enter All the Parameters");
    }
    /*foreach( QLineEdit* item, allLineEdits ) {
        std::cout << item->text().toStdString() << '\n';
    }*/

    inferencer_params_map["conf_thresh"] = inferencer_params->findChild<QLineEdit*>("lineEdit_deployer_confidence_thresh")->text().toStdString();
    inferencer_params_map["scaling_factor"] = inferencer_params->findChild<QLineEdit*>("lineEdit_deployer_inferencer_scaling_factor")->text().toStdString();
    inferencer_params_map["inpWidth"] = inferencer_params->findChild<QLineEdit*>("lineEdit_inferencer_input_width")->text().toStdString();
    inferencer_params_map["inpHeight"] = inferencer_params->findChild<QLineEdit*>("lineEdit_inferencer_input_height")->text().toStdString();
    inferencer_params_map["mean_sub_blue"] = inferencer_params->findChild<QLineEdit*>("lineEdit_mean_sub_blue")->text().toStdString();
    inferencer_params_map["mean_sub_green"] = inferencer_params->findChild<QLineEdit*>("lineEdit_mean_sub_green")->text().toStdString();
    inferencer_params_map["mean_sub_red"] = inferencer_params->findChild<QLineEdit*>("lineEdit_mean_sub_red")->text().toStdString();


    return true;

}
