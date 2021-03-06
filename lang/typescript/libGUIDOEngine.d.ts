declare var Module: any;

// GUIDOEngine
//--------------------------------------------------------------
declare enum GuidoMapping {}
declare enum GuidoErrCode {}

interface ARHandler     {}
interface GRHandler     {}

interface GuidoParser   {}
interface GuidoStream   {}
interface VGDevice      {}

interface GuidoInitDesc {
    graphicDevice:  VGDevice;
    reserved:       void;
    musicFont:      string;
    textFont:       string;
}

interface GuidoDate {
    num:    number;
    denom:  number;
}

interface GuidoPageFormat {
    width:          number; 
    height:         number; 
    marginleft:     number; 
    margintop:      number; 
    marginright:    number; 
    marginbottom:   number;
}

interface GuidoLayoutSettings {
	systemsDistance:        number;
	systemsDistribution:    number;
	systemsDistribLimit:    number;
	force:                  number;
    spring:                 number;
	neighborhoodSpacing:    number;
	optimalPageFill:        number;
	resizePage2Music:       number;
	proportionalRenderingForceMultiplicator: number;
}

interface GuidoOnDrawDesc {
    handle:         GRHandler;
    hdc:            VGDevice;
    page:           number;
	updateRegion:   GPaintStruct ;
    scrollx:        number; 
    scrolly:        number;
    reserved:       number;
    sizex:          number;
    sizey:          number;
    isprint:        number;
}

interface GuidoVersion {
    major:  number;
    minor:  number;
    sub:    number;
    str:    string;
}

interface ParserError {
    line:   number;
    col:    number;
    msg:    string;
}

interface GPaintStruct {
    erase:  boolean;
    left:   number;
	top:    number;
	right:  number;
	bottom: number;
}

interface GuidoEngineAdapter {
    constructor: GuidoEngineAdapter;
        
    init        (desc?: GuidoInitDesc): GuidoErrCode;
    shutdown    (): void;
    
	ar2gr               (ar: ARHandler): GRHandler;
	ar2grSettings       (ar: ARHandler, settings: GuidoLayoutSettings): GRHandler;	    	
    updateGR            (gr: GRHandler): GuidoErrCode;
    updateGRSettings    (gr: GRHandler, settings: GuidoLayoutSettings): GuidoErrCode;

	freeAR      (ar: ARHandler): void;
	freeGR      (gr: GRHandler): void;
    
    getErrorString              (errCode: GuidoErrCode): string;	
	getDefaultLayoutSettings    (): GuidoLayoutSettings; 
    	
    countVoices     (inHandleAR: ARHandler): number;
	
    getPageCount    (inHandleGR: GRHandler): number;	
    getSystemCount  (inHandleGR: GRHandler, page: number): number;

    duration        (inHandleGR: GRHandler): GuidoDate;

	findEventPage   (inHandleGR: GRHandler , date: GuidoDate): number;
	findPageAt      (inHandleGR: GRHandler, date: GuidoDate): number;

    getPageDate     (inHandleGR: GRHandler, pageNum: number): GuidoDate;
		
	onDraw          (desc: GuidoOnDrawDesc): GuidoErrCode;

    gr2SVG  (handle: GRHandler, page: number, embedFont: boolean, mappingMode: number): string;

    abstractExport  (handle: GRHandler, page: number): string;

    binaryExport    (handle: GRHandler, page: number): string;

	javascriptExport(handle: GRHandler, page: number): GuidoErrCode ;

	setDrawBoundingBoxes    (bbMap: number): void;
	getDrawBoundingBoxes    (): number;

    getPageFormat           (inHandleGR: GRHandler, pageNum: number): GuidoPageFormat;
    setDefaultPageFormat    (format: GuidoPageFormat): void;
	getDefaultPageFormat    (): GuidoPageFormat; 

    unit2CM     (val: number): number;
	cm2Unit     (val: number): number;
	unit2Inches (val: number): number;
    inches2Unit (val: number): number;

    resizePageToMusic   (inHandleGR: GRHandler): GuidoErrCode;
		
	getVersion          (): GuidoVersion;
    checkVersionNums    (major: number, minor: number, sub: number): GuidoErrCode;

	getLineSpace        (): number;

    markVoice   (inHandleAR: ARHandler, voicenum: number,
                date: GuidoDate, duration: GuidoDate,
                red: string, green: string, blue: string ): GuidoErrCode;

    setSymbolPath   (inHandleAR: ARHandler, inPaths: Array<string>): GuidoErrCode;
    getSymbolPath   (inHandleAR: ARHandler): Array<string>;

    getParsingTime  (ar: ARHandler): number;
	getAR2GRTime    (gr: GRHandler): number;
    getOnDrawTime   (gr: GRHandler): number;

    openParser      (): GuidoParser;
    closeParser     (p: GuidoParser): GuidoErrCode;

    file2AR     (parser: GuidoParser, file: string): ARHandler;
    string2AR   (parser: GuidoParser, gmnCode: string): ARHandler;

    getStream   (gStream: GuidoStream): string;
    stream2AR   (p: GuidoParser,stream: GuidoStream): ARHandler;

    parserGetErrorCode (p: GuidoParser): ParserError;

    openStream      (): GuidoStream;
    closeStream     (s: GuidoStream): GuidoErrCode;
    writeStream     (s: GuidoStream, str: string): GuidoErrCode;
	resetStream     (s: GuidoStream): GuidoErrCode;
}

// GUIDOMap
//--------------------------------------------------------------
declare enum GuidoElementSelector   {}
declare enum GuidoElementType       {}

//declare var MapElement      : [FloatRect, RectInfos];
//declare var TimeMapElement  : [TimeSegment, TimeSegment];
//declare var Time2GraphicMap : [TimeSegment, FloatRect];
//declare var pairDate        : [GuidoDate, GuidoDate]; 
interface TimeSegment {
    start   : GuidoDate,
    end     : GuidoDate,
}

interface Rect {
	left    : number;
	top     : number;
	right   : number;
	bottom  : number;
}

interface Element {
    rect        : Rect;
    rectInfos   : RectInfos;
}
interface MapElement {
    map: Array<Element>;
}

interface TimeMapElement {
    map: Array<TimeSegment>;
}

interface Time2GraphicElt {
    time: TimeSegment;
    rect: Rect;
}
interface Time2GraphicMap {
	map: Array<Time2GraphicElt>;
}

interface MapCollector {
    Graph2TimeMap   (box: Rect, dates: TimeSegment, infos: GuidoElementInfos): void;
}

interface RectInfos {
    ftime   : TimeSegment;	
    fInfos  : GuidoElementInfos;
    time()  : TimeSegment;
	infos() : GuidoElementInfos;	
}

interface TimeMapCollector {
    Time2TimeMap    (from: TimeSegment, to: TimeSegment): void ;
}

interface GuidoElementInfos {
	type        : GuidoElementType;		
	staffNum    : number;	
	voiceNum    : number;	
    midiPitch   : number; 
}

interface GuidoScoreMapAdapter {
    constructor: GuidoScoreMapAdapter;

//    getMap          (gr: GRHandler, pagenum: number, width: number, height: number, sel: GuidoElementSelector, f: MapCollector): GuidoErrCode;
    getPageMap      (gr: GRHandler, pagenum: number, w: number, h: number)                      : Time2GraphicMap;
    getStaffMap     (gr: GRHandler, pagenum: number, w: number, h: number, staff: number)       : Time2GraphicMap;
    getVoiceMap     (gr: GRHandler, pagenum: number, w: number, h: number, voice: number)       : Time2GraphicMap;
    getSystemMap    (gr: GRHandler, pagenum: number, w: number, h: number)                      : Time2GraphicMap;
    getTime         (date: GuidoDate, map: Time2GraphicMap, t: TimeSegment, r: Rect)            : boolean;
    getPoint        (x: number, y: number, map: Time2GraphicMap, t: TimeSegment, r: Rect)       : boolean;
    getTimeMap      (gr: ARHandler, f: TimeMapCollector)                                        : GuidoErrCode;
}

interface TimeSegment /*implements pairDate*/ {
    constructor: TimeSegment;
	empty       () : boolean;
	intersect   (ts: TimeSegment): boolean;
	include     (date: GuidoDate): boolean;
	include     (ts: TimeSegment): boolean;
}

// GUIDOFactory
//--------------------------------------------------------------
interface ARFactoryHandler {} 

interface GUIDOFactoryAdapter {
	factory: ARFactoryHandler;
    constructor: GUIDOFactoryAdapter;
	
	openMusic   () : GuidoErrCode;
	closeMusic  () : ARHandler;

    openVoice   () : GuidoErrCode;
    closeVoice  () : GuidoErrCode;

    openChord   () : GuidoErrCode;
    closeChord  () : GuidoErrCode;

    insertCommata(): GuidoErrCode;
	
    openEvent   (inEventName: string): GuidoErrCode;
    closeEvent  (): GuidoErrCode;

    addSharp    (): GuidoErrCode ;
    addFlat     (): GuidoErrCode;

    setEventDots        (dots: number): GuidoErrCode;
    setEventAccidentals (accident: number): GuidoErrCode;

    setOctave   (octave: number): GuidoErrCode;
    setDuration (numerator: number, denominator: number): GuidoErrCode;

    openTag                 (name: string, tagID: number): GuidoErrCode;
    openRangeTag            (name: string, tagID: number): GuidoErrCode;
    endTag                  (): GuidoErrCode;
    closeTag                (): GuidoErrCode;
    addTagParameterString   (val: string): GuidoErrCode;
    addTagParameterInt      (val: number): GuidoErrCode;
    addTagParameterFloat    (val: number): GuidoErrCode;

    setParameterName(name: string): GuidoErrCode;
    setParameterUnit(unit: string): GuidoErrCode;
}

// GUIDOPianoRoll
//--------------------------------------------------------------
declare enum PianoRollType  {}

interface LimitParams {
    startDate   : GuidoDate;
    endDate     : GuidoDate;
    lowPitch    : number;
    highPitch   : number;    
}

interface PianoRoll {}

interface GUIDOPianoRollAdapter {
	constructor: GUIDOPianoRollAdapter;
		
    ar2PianoRoll    (type: PianoRollType, arh: ARHandler): PianoRoll;
    //midi2PianoRoll  (type: PianoRollType, midiFileName: string): PianoRoll;

    destroyPianoRoll(pr: PianoRoll): GuidoErrCode;
    
    setLimits       (pr: PianoRoll, limitParams: LimitParams): GuidoErrCode;

    enableKeyboard  (pr: PianoRoll, enabled: boolean): GuidoErrCode;
    getKeyboardWidth(pr: PianoRoll, height: number): number;

    enableAutoVoicesColoration  (pr: PianoRoll, enabled: boolean): GuidoErrCode;
    setRGBColorToVoice          (pr: PianoRoll, voiceNum: number, r: number, g: number, b: number, a: number): GuidoErrCode;
    setHtmlColorToVoice         (pr: PianoRoll, voiceNum: number, color: number): GuidoErrCode;
    removeColorToVoice          (pr: PianoRoll, voiceNum: number): GuidoErrCode;

    enableMeasureBars           (pr: PianoRoll, enabled: boolean): GuidoErrCode;

    setPitchLinesDisplayMode    (pr: PianoRoll, mode: number): GuidoErrCode;

    getMap          (pr: PianoRoll, width: number, height: number): Time2GraphicMap;

    onDraw          (pr: PianoRoll, width: number, height: number, dev: VGDevice): GuidoErrCode;

	svgExport       (pr: PianoRoll, width: number, height: number): string;

    javascriptExport(pr: PianoRoll, width: number, height: number): GuidoErrCode;
}