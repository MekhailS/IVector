#pragma once
#include <cstddef>
#include "IVector.h"
#include "RC.h"

class ISet {
public:
	static ISet* createSet(Logger* pLogger);

	static ISet* cap(ISet const * const& op1, ISet const * const& op2, IVector::NORM n, double tol, Logger* pLogger);
	static ISet* cup(ISet const * const& op1, ISet const * const& op2, IVector::NORM n, double tol, Logger* pLogger);
	static ISet* sub(ISet const * const& op1, ISet const * const& op2, IVector::NORM n, double tol, Logger* pLogger);
	static ISet* symSub(ISet const * const& op1, ISet const * const& op2, IVector::NORM n, double tol, Logger* pLogger);

	static bool equals(ISet const * const& op1, ISet const * const& op2, IVector::NORM n, double tol, Logger* pLogger);
	static bool subSet(ISet const * const& op1, ISet const * const& op2, IVector::NORM n, double tol, Logger* pLogger);

	virtual size_t getDim() const = 0;
	virtual size_t getSize() const = 0;

	virtual RC get(size_t index, IVector const *& val) const = 0;
	virtual RC findFirst(ISet const * const& pat, IVector::NORM n, double tol, IVector const *& val) const = 0;

	virtual RC insert(ISet const *& val, IVector::NORM n, double tol) = 0;

	virtual RC remove(size_t index) = 0;
	virtual RC remove(ISet const * const& pat, IVector::NORM n, double tol) = 0;

	virtual ~ISet() = 0;

private:	
	ISet(const ISet& other);
	ISet &operator=(const ISet& other);

protected:
	ISet() = default;
};
