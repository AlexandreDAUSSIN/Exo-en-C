#include "nat_op.h"

nat sum(nat x, nat y) {
  if (is_invalid(x) || is_invalid(y)) {
    return invalid();
  }
  if (is_zero(x)) {
    return y;
  }
  return sum(pred(x), succ(y));
}

nat dist(nat x, nat y){
  if (is_invalid(x) || is_invalid(y)) {
    return invalid();
  }
  if (is_zero(x)) {
    return y;
  }
  if (is_zero(y)) {
    return x;
  }
  return dist(pred(x), succ(y));
}

nat min(nat x, nat y){
  if (is_invalid(x) || is_invalid(y)) {
    return invalid();
  }
  if (is_zero(x)) {
    return x;
  }
  if (is_zero(y)) {
    return y;
  }
  return min(pred(x), succ(y));
}

nat max(nat x, nat y){
  if (is_invalid(x) || is_invalid(y)) {
    return invalid();
  }
  if (is_zero(x)) {
    return y;
  }
  if (is_zero(y)) {
    return x;
  }
  return max(pred(x), succ(y));
}

bool is_eq(nat x, nat y){
  if (is_invalid(x) || is_invalid(y)) {
    return invalid();
  }
  if (is_zero(x)) {
    return is_zero(y);
  }
  if (is_zero(y)) {
    return false;
  }
  return is_eq(pred(x), succ(y));
}

bool is_neq(nat x, nat y){
  if (is_invalid(x) || is_invalid(y)) {
    return invalid();
  }
  if (is_zero(x) && is_zero(y)) {
    return false;
  }
  return is_neq(pred(x), succ(y));
}

bool is_leq(nat x, nat y){
  if (is_invalid(x) || is_invalid(y)) {
    return invalid();
  }
  if (is_zero(x)) {
    return true;
  }
  if (is_zero(y)) {
    return false;
  }
  return is_leq(pred(x), succ(y));
}

bool is_lth(nat x, nat y){
  if (is_invalid(x) || is_invalid(y)) {
    return invalid();
  }
  if (is_zero(x) && is_zero(y)) {
    return false;
  }
  return is_lth(pred(x), succ(y));
}

bool is_geq(nat x, nat y){
    if (is_invalid(x) || is_invalid(y)) {
    return invalid();
  }
  if (is_zero(x)){
    return is_zero(y);
  }
  return is_geq(pred(x), succ(y));
}

bool is_gth(nat x, nat y){
    if (is_invalid(x) || is_invalid(y)) {
    return invalid();
  }
  if (is_zero(x) && is_zero(y)){
    return false;
  }
  return is_geq(pred(x), succ(y));
}
