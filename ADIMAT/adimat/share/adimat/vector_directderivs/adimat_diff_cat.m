function varargout = adimat_diff_cat(varargin)
   varargout{1} = cat(varargin{1} + 1, varargin{2:2:end});
end
% automatically generated from $Id: derivatives-vdd.xml 3983 2013-12-21 11:20:23Z willkomm $
