function varargout = adimat_diff_sort2(varargin)
[varargout{2}, varargout{3}]= sort(varargin{2});
if isvector(varargin{2}), 
varargout{1}= varargin{1}(varargout{3});
else
tmp1= size(varargin{2});
varargout{1}= varargin{1}(varargout{3}+ ones(tmp1(1), 1)* (0:tmp1(2):numel(varargin{2})-1));
end
end
% automatically generated from $Id: derivatives-vdd.xml 3983 2013-12-21 11:20:23Z willkomm $
