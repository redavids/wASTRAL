#ifndef QUARTET_HPP__
#define QUARTET_HPP__
#include <map>
#include <boost/multi_array.hpp>
#include "TaxonSet.hpp"

class Quartet {
public:
  Quartet(TaxonSet& ts, Taxon a, Taxon b, Taxon c, Taxon d);
  Quartet(TaxonSet& ts) : ts(ts) {}
  double parse(char* str);
  void parse_newick(char* str);
  void parse_wqmc(char* str);

  string str();
  static void test();
  int a() { return taxa[0]; }
  int b() { return taxa[1]; }
  int c() { return taxa[2]; }
  int d() { return taxa[3]; }
private:
  Taxon taxa[4];
  TaxonSet& ts;
};

class QuartetDict {
public:
  QuartetDict(TaxonSet& ts, string quartetfile);
  double operator()(Taxon a, Taxon b, Taxon c, Taxon d);
  double operator()(Quartet& q);
  string str();
  static void test();
private:
  typedef boost::multi_array<double, 4> array_type;
  array_type array;
  TaxonSet& ts;
};

#endif // QUARTET_HPP__
