UValue::UValue(value, units) {
    this->value = value;
    this->units = units;
}

UValue::get_value() {
    return this->value;
}

UValue::get_units() {
    return this->units;
}
