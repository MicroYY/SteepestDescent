#include "SteepestDescent.h"

Eigen::VectorXd SteepestDescent::computeMin(Eigen::VectorXd _initPt, int _maxIter, double epsilon)
{
	Eigen::VectorXd xk = _initPt;
	Eigen::VectorXd gk;
	Eigen::VectorXd pk;
	double ak;
	for (size_t i = 0; i < _maxIter; i++)
	{
		gk = G * xk + b;
		if (gk.norm() < epsilon)
		{
			break;
		}
		pk = -gk;
		ak = -gk.transpose()*pk;
		ak /= pk.transpose() * G * pk;
		xk += ak * pk;
	}
	return xk;
}
