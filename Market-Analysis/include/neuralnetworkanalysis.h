#ifndef NEURALNETWORKANALYSIS_H
#define NEURALNETWORKANALYSIS_H

#include <QObject>
#include "include/settingsstruct.h"
#include "include/imt4reader.h"

class NeuralNetworkAnalysis : public QObject
{
    Q_OBJECT
public:
    explicit NeuralNetworkAnalysis(QObject *parent = 0);
    ~NeuralNetworkAnalysis();

private:
    ConfigMT4                       *config;
    qint64                          firstEntryTime;
    qint64                          lastEntryTime;

public slots:
    void setConfigKit(ConfigMT4 *cfg);
    void runTraining(void);
    void runPrediction(void);
    void stop(void);

private slots:
    bool loadTrainedModel(void);
    void prepareDataSet(FileType historyType);
    void prepareVariablesInfo(void);
    void prepareInstances(void);
    void prepareNeuralNetwork(void);
    void preparePerformanceFunc(void);
    void runTrainingNeuralNetwork(void);
    void saveResultsTraining(void);
    void runWorkingProcess(void);

    void loadHistoryFiles(QMap<QString, IMt4Reader *> &readers,
                          QMap<QString, qint32> &iters,
                          FileType historyType);
    void loadDataToMatrixDS(const QMap<QString, IMt4Reader *> &readers,
                            QMap<QString, qint32> &iters,
                            Matrix<double> &matrixDS);
    void getFirstEntryTime(const QMap<QString, IMt4Reader *> &readers,
                           qint64 &first, qint64 &last);
    double getDoubleTimeSymbol(const QString &symbol, const qint64 &timeCurrentIter);
    //void parseNNExeption();

signals:
    void trained(void);
    void progress(qint32);
    void message(QString);
    void pause(qint32);
};

#endif // NEURALNETWORKANALYSIS_H
