#include <lib/class/Slot/UintSlot.h>


Optr layout_Slot_UintSlot_Class_class;
Optr layout_Slot_UintSlot;


static void init_SMB_readFrom_() {
    Symbol SMB_readFrom_ = new_Symbol(L"readFrom:");
    Variable VAR_anObject_0_0 = new_Variable_named(L"anObject", 0);
    Array PArray21999 = new_Array_with(1, (Optr)VAR_anObject_0_0);
    Symbol SMB_pPrimitive_plugin_ = new_Symbol(L"pPrimitive:plugin:");
    Symbol SMB_Slot_minus_UintSlot = new_Symbol(L"Slot.UintSlot");
    Annotation PAnnotation22001 = new_Annotation((Optr)SMB_pPrimitive_plugin_, 2, (Optr)SMB_readFrom_, (Optr)SMB_Slot_minus_UintSlot);
    Array PArray22000 = new_Array_with(1, (Optr)PAnnotation22001);
    Symbol SMB_pinocchioPrimitiveFailed = new_Symbol(L"pinocchioPrimitiveFailed");
    // pinocchioPrimitiveFailed. 
    Send PSend22003 = new_Send((Optr)self, SMB_pinocchioPrimitiveFailed, 0);
    Array PThreadedCode22002 = instantiate_Array_with(ThreadedCode_Class, 0, 5, (Optr)&t_push_self, (Optr)&t_send0, (Optr)PSend22003, (Optr)&t_zap, (Optr)&t_method_return_self);
    NativeMethod PNativeMethod21998 = new_NativeMethod_with(PArray21999, empty_Array, PArray22000, PThreadedCode22002, 2, PSend22003, self);
    
    MethodClosure MC_SMB_readFrom_ = new_MethodClosure((Method)PNativeMethod21998, UintSlot_Class);
    store_method(UintSlot_Class, SMB_readFrom_, MC_SMB_readFrom_);
}


static void init_SMB_aliasFrom_to_in_() {
    Symbol SMB_aliasFrom_to_in_ = new_Symbol(L"aliasFrom:to:in:");
    Variable VAR_anObject_0_0 = new_Variable_named(L"anObject", 0);
    Variable VAR_anotherObject_0_1 = new_Variable_named(L"anotherObject", 0);
    Variable VAR_aContext_0_2 = new_Variable_named(L"aContext", 0);
    Array PArray22005 = new_Array_with(3, (Optr)VAR_anObject_0_0, (Optr)VAR_anotherObject_0_1, (Optr)VAR_aContext_0_2);
    Symbol SMB_readFrom_ = new_Symbol(L"readFrom:");
    // readFrom:. 
    Send PSend22007 = new_Send((Optr)self, SMB_readFrom_, 1, (Optr)VAR_anObject_0_0);
    Symbol SMB_assign_on_ = new_Symbol(L"assign:on:");
    // assign:on:. 
    Send PSend22008 = new_Send((Optr)self, SMB_assign_on_, 2, (Optr)PSend22007, (Optr)VAR_anotherObject_0_1);
    Array PThreadedCode22006 = instantiate_Array_with(ThreadedCode_Class, 0, 11, (Optr)&t_push_self, (Optr)&t_push_self, (Optr)&t_push_variable, (Optr)VAR_anObject_0_0, (Optr)&t_send1, (Optr)PSend22007, (Optr)&t_push_variable, (Optr)VAR_anotherObject_0_1, (Optr)&t_send2, (Optr)PSend22008, (Optr)&t_method_return);
    Method PMethod22004 = new_Method_with(PArray22005, empty_Array, empty_Array, PThreadedCode22006, 1, PSend22008);
    
    MethodClosure MC_SMB_aliasFrom_to_in_ = new_MethodClosure((Method)PMethod22004, UintSlot_Class);
    store_method(UintSlot_Class, SMB_aliasFrom_to_in_, MC_SMB_aliasFrom_to_in_);
}


static void init_SMB_assign_on_() {
    Symbol SMB_assign_on_ = new_Symbol(L"assign:on:");
    Variable VAR_value_0_0 = new_Variable_named(L"value", 0);
    Variable VAR_anObject_0_1 = new_Variable_named(L"anObject", 0);
    Array PArray22010 = new_Array_with(2, (Optr)VAR_value_0_0, (Optr)VAR_anObject_0_1);
    Symbol SMB_pPrimitive_plugin_ = new_Symbol(L"pPrimitive:plugin:");
    Symbol SMB_Slot_minus_UintSlot = new_Symbol(L"Slot.UintSlot");
    Annotation PAnnotation22012 = new_Annotation((Optr)SMB_pPrimitive_plugin_, 2, (Optr)SMB_assign_on_, (Optr)SMB_Slot_minus_UintSlot);
    Array PArray22011 = new_Array_with(1, (Optr)PAnnotation22012);
    Symbol SMB_pinocchioPrimitiveFailed = new_Symbol(L"pinocchioPrimitiveFailed");
    // pinocchioPrimitiveFailed. 
    Send PSend22014 = new_Send((Optr)self, SMB_pinocchioPrimitiveFailed, 0);
    Array PThreadedCode22013 = instantiate_Array_with(ThreadedCode_Class, 0, 5, (Optr)&t_push_self, (Optr)&t_send0, (Optr)PSend22014, (Optr)&t_zap, (Optr)&t_method_return_self);
    NativeMethod PNativeMethod22009 = new_NativeMethod_with(PArray22010, empty_Array, PArray22011, PThreadedCode22013, 2, PSend22014, self);
    
    MethodClosure MC_SMB_assign_on_ = new_MethodClosure((Method)PNativeMethod22009, UintSlot_Class);
    store_method(UintSlot_Class, SMB_assign_on_, MC_SMB_assign_on_);
}


static void init_SMB_accept_() {
    Symbol SMB_accept_ = new_Symbol(L"accept:");
    Variable VAR_visitor_0_0 = new_Variable_named(L"visitor", 0);
    Array PArray22016 = new_Array_with(1, (Optr)VAR_visitor_0_0);
    Symbol SMB_visitUnsintSlot_ = new_Symbol(L"visitUnsintSlot:");
    // visitUnsintSlot:. 
    Send PSend22018 = new_Send((Optr)VAR_visitor_0_0, SMB_visitUnsintSlot_, 1, (Optr)self);
    Array PThreadedCode22017 = instantiate_Array_with(ThreadedCode_Class, 0, 6, (Optr)&t_push_variable, (Optr)VAR_visitor_0_0, (Optr)&t_push_self, (Optr)&t_send1, (Optr)PSend22018, (Optr)&t_method_return);
    Method PMethod22015 = new_Method_with(PArray22016, empty_Array, empty_Array, PThreadedCode22017, 1, PSend22018);
    
    MethodClosure MC_SMB_accept_ = new_MethodClosure((Method)PMethod22015, UintSlot_Class);
    store_method(UintSlot_Class, SMB_accept_, MC_SMB_accept_);
}


static void init_SMB_assignFor_to_() {
    Symbol SMB_assignFor_to_ = new_Symbol(L"assignFor:to:");
    Variable VAR_visitor_0_0 = new_Variable_named(L"visitor", 0);
    Variable VAR_value_0_1 = new_Variable_named(L"value", 0);
    Array PArray22020 = new_Array_with(2, (Optr)VAR_visitor_0_0, (Optr)VAR_value_0_1);
    Symbol SMB_assignUnsintSlot_to_ = new_Symbol(L"assignUnsintSlot:to:");
    // assignUnsintSlot:to:. 
    Send PSend22022 = new_Send((Optr)VAR_visitor_0_0, SMB_assignUnsintSlot_to_, 2, (Optr)self, (Optr)VAR_value_0_1);
    Array PThreadedCode22021 = instantiate_Array_with(ThreadedCode_Class, 0, 8, (Optr)&t_push_variable, (Optr)VAR_visitor_0_0, (Optr)&t_push_self, (Optr)&t_push_variable, (Optr)VAR_value_0_1, (Optr)&t_send2, (Optr)PSend22022, (Optr)&t_method_return);
    Method PMethod22019 = new_Method_with(PArray22020, empty_Array, empty_Array, PThreadedCode22021, 1, PSend22022);
    
    MethodClosure MC_SMB_assignFor_to_ = new_MethodClosure((Method)PMethod22019, UintSlot_Class);
    store_method(UintSlot_Class, SMB_assignFor_to_, MC_SMB_assignFor_to_);
}

void init_Slot_PUintSlot_layout() {
    layout_Slot_UintSlot_Class_class = (Optr)create_layout_with_vars(ObjectLayout_Class, 5);
    ((Array)layout_Slot_UintSlot_Class_class)->values[0] = slot_Kernel_Object_Object_Class_class_layout; // layout 
    ((Array)layout_Slot_UintSlot_Class_class)->values[1] = slot_Kernel_Object_Object_Class_class_superclass; // superclass 
    ((Array)layout_Slot_UintSlot_Class_class)->values[2] = slot_Kernel_Object_Object_Class_class_methods; // methods 
    ((Array)layout_Slot_UintSlot_Class_class)->values[3] = slot_Kernel_Object_Object_Class_class_name; // name 
    ((Array)layout_Slot_UintSlot_Class_class)->values[4] = slot_Kernel_Object_Object_Class_class_package; // package 
    
    Symbol  SMB_UintSlot = new_Symbol(L"UintSlot");
    layout_Slot_UintSlot = (Optr)create_layout_with_vars(ObjectLayout_Class, 3);
    ((Array)layout_Slot_UintSlot)->values[0] = slot_Slot_AbstractSlot_index; // index 
    ((Array)layout_Slot_UintSlot)->values[1] = slot_Slot_AbstractSlot_name; // name 
    ((Array)layout_Slot_UintSlot)->values[2] = slot_Slot_AbstractSlot_package; // package 
    UintSlot_Class = (Class)new_Class(AbstractSlot_Class, layout_Slot_UintSlot_Class_class);
    UintSlot_Class->layout = layout_Slot_UintSlot;
    UintSlot_Class->name = SMB_UintSlot;
    
}

void init_Slot_PUintSlot_methods() {
    init_SMB_readFrom_();
    init_SMB_aliasFrom_to_in_();
    init_SMB_assign_on_();
    init_SMB_accept_();
    init_SMB_assignFor_to_();
    
}